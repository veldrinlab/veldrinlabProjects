/**
 * File contains definition of Quaternion class.
 * @file    Quatenion.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-20
 * @version 1.0
 */

#include "Quaternion.hpp"

namespace math {

/**
 * Definition of Quaternion class static members that represents identiy quaternion.
 */
const Quaternion Quaternion::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f);

/**
 * Default constructor, set all values to zero.
 */
Quaternion::Quaternion()
{
	w = 0.0f;
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

/**
 * Constructor with initialization values - quaternion memebrs.
 * @param   w is scalar parameter.
 * @param   x is vector x parameter.
 * @param   y is vector y parameter.
 * @param   z is vector z parameter.
 */
Quaternion::Quaternion(const float w,const float x,const float y,const float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

/**
 * Constructor with initialization values - euler angles.
 * @param   headDegrees is zAxis angle.
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle.
 */
Quaternion::Quaternion(float headDegrees, float pitchDegrees, float rollDegrees)
{
    fromHeadPitchRoll(headDegrees, pitchDegrees, rollDegrees);
}

/**
 * Constructor with initialization values - axis vector and angle degrees.
 * @param   axis is direction axis vector.
 * @param   degrees is rotate angles.
 */
Quaternion::Quaternion(const Vector3D &axis, float degrees)
{
    fromAxisAngle(axis, degrees);
}

/**
 * Constructor with initialization values - matrix.
 * @param   m is rotation matrix.
 */
Quaternion::Quaternion(const Matrix4 &m)
{
    fromMatrix(m);
}

/**
 * Destructor, nothing to do.
 */
Quaternion::~Quaternion()
{

}

/**
 * Class equal operator.
 * @param   rhs is quaternion which we check if it is equal.
 * @return  true if quaternion are equal.
 */
bool Quaternion::operator==(const Quaternion& rhs) const
{
    return (w == rhs.w && x == rhs.x
        && y == rhs.y && z == rhs.z);
}

/**
 * Class not-equal operator.
 * @param   rhs is quaternion which we check if it is not equal.
 * @return  true if quaternions are not equal.
 */
bool Quaternion::operator!=(const Quaternion& rhs) const
{
    return !(*this == rhs);
}

/**
 * Class quaternion to quaternion addition operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of addition operation.
 */
Quaternion& Quaternion::operator+=(const Quaternion& rhs)
{
    w += rhs.w, x += rhs.x, y += rhs.y, z += rhs.z;
    return *this;
}

/**
 * Class quaternion to quaternion substraction operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of substraction operation.
 */
Quaternion& Quaternion::operator-=(const Quaternion& rhs)
{
    w -= rhs.w, x -= rhs.x, y -= rhs.y, z -= rhs.z;
    return *this;
}

/* TODO:
   ERROR (?)
   operator *= dzia³a b³êdnie (wg mnie w paru miejscach pomylone minusy i plusy)*/
/**
 * Class multiply by quaternion operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of multiply operation.
 */
Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
    Quaternion tmp(
        (w * rhs.w) - (x * rhs.x) - (y * rhs.y) - (z * rhs.z),
        (w * rhs.x) + (x * rhs.w) - (y * rhs.z) + (z * rhs.y),
        (w * rhs.y) + (x * rhs.z) + (y * rhs.w) - (z * rhs.x),
        (w * rhs.z) - (x * rhs.y) + (y * rhs.x) + (z * rhs.w));


    *this = tmp;
    return *this;
}

/**
 * Class multiply by scalar operator.
 * @param   scalar is scalar.
 * @return  quaternion that is result of multiply operation.
 */
Quaternion& Quaternion::operator*=(const float scalar)
{
    w *= scalar, x *= scalar, y *= scalar, z *= scalar;
    return *this;
}

/**
 * Class divide by scalar operator.
 * @param   scalar is scalar.
 * @return  quaternion that is result of divide operation.
 */
Quaternion& Quaternion::operator/=(const float scalar)
{
    w /= scalar, x /= scalar, y /= scalar, z /= scalar;
    return *this;
}

/**
 * Class quaternion to quaternion addition operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of addition operation.
 */
Quaternion Quaternion::operator+(const Quaternion& rhs) const
{
    Quaternion tmp(*this);
    tmp += rhs;
    return tmp;
}

/**
 * Class quaternion to quaternion substraction operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of substraction operation.
 */
Quaternion Quaternion::operator-(const Quaternion& rhs) const
{
    Quaternion tmp(*this);
    tmp -= rhs;
    return tmp;
}

/**
 * Class multiply by quaternion operator.
 * @param   rhs is second quaternion.
 * @return  quaternion that is result of multiply operation.
 */
Quaternion Quaternion::operator*(const Quaternion& rhs) const
{
    Quaternion tmp(*this);
    tmp *= rhs;
    return tmp;
}

/**
 * Class multiply by scalar operator.
 * @param   scalar is scalar.
 * @return  quaternion that is result of multiply operation.
 */
Quaternion Quaternion::operator*(const float scalar) const
{
    Quaternion tmp(*this);
    tmp *= scalar;
    return tmp;
}

/**
 * Class divide by scalar operator.
 * @param   scalar is scalar.
 * @return  quaternion that is result of divide operation.
 */
Quaternion Quaternion::operator/(const float scalar) const
{
    Quaternion tmp(*this);
    tmp /= scalar;
    return tmp;
}

/**
 * Method is used to conjugate quaternion.
 * @return	conjugated quaternion.
 */
Quaternion Quaternion::conjugate() const
{
    Quaternion tmp(w, -x, -y, -z);
    return tmp;
}

/**
 * Method is used to create quaternion orientation from direction vector and angle degrees.
 * @param   axis is direction axis vector.
 * @param   degrees is rotate angles.
 */
void Quaternion::fromAxisAngle(const Vector3D& axis, float degrees)
{
    float halfTheta = (3.14f * degrees / 180) * 0.5f;
    float s = sinf(halfTheta);
    w = cosf(halfTheta), x = axis.x * s, y = axis.y * s, z = axis.z * s;
}

/**
 * Method is used to create quaternion from euler angles.
 * @param   headDegrees is zAxis angle.
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle.
 */
void Quaternion::fromHeadPitchRoll(float headDegrees, float pitchDegrees, float rollDegrees)
{
    Matrix4 m;
    m.fromHeadPitchRoll(headDegrees, pitchDegrees, rollDegrees);
    fromMatrix(m);
}

/**
 * Method is used to create identity quaternion.
 */
void Quaternion::identity()
{
    w = 1.0f;
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

/**
 * Method used to inverse quaternion.
 * @return	inverted quaternion.
 */
Quaternion Quaternion::inverse() const
{
    float invMag = 1.0f / magnitude();
    return conjugate() * invMag;
}

/**
 * Method used to calculate quaternion magnitude.
 * @return	calculated magnitude value.
 */
float Quaternion::magnitude() const
{
    return sqrtf(w * w + x * x + y * y + z * z);
}

/**
 * Method used to normalize quaternion.
 */
void Quaternion::normalize()
{
    float invMag = 1.0f / magnitude();
    w *= invMag, x *= invMag, y *= invMag, z *= invMag;
}

/**
 * Method used to set quaternion values.
 * @param	w is w value.
 * @param   x is x value.
 * @param   y is y value.
 * @param   z is z value.
 */
void Quaternion::set(const float w, const float x, const float y, const float z)
{
    this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

/**
 * Method is used to extract the Euler angles from quaternion.
 * @param   headDegrees is zAxis angle.
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle.
 */
void Quaternion::toHeadPitchRoll(float& headDegrees, float& pitchDegrees, float& rollDegrees) const
{
    Matrix4 m = toMatrix4();
    m.toHeadPitchRoll(headDegrees, pitchDegrees, rollDegrees);
}

/* TODO:
   ERROR (?)
   nie jestem pewna, czy to b³¹d, ale w wyniku, zamiast spodziewanego 
   kwaterniona dostajemy (- kwaternion) */
/**
 * Method is used to create quaternion from a rotation matrix. 
 * @param	m is rotation matrix.
 */
void Quaternion::fromMatrix(const Matrix4 &m)
{
    float s = 0.0f;
    float q[4] = {0.0f};
    float trace = m[0][0] + m[1][1] + m[2][2];

    if (trace > 0.0f)
    {
        s = sqrtf(trace + 1.0f);
        q[3] = s * 0.5f;
        s = 0.5f / s;
        q[0] = (m[1][2] - m[2][1]) * s;
        q[1] = (m[2][0] - m[0][2]) * s;
        q[2] = (m[0][1] - m[1][0]) * s;
    }
    else
    {
        int nxt[3] = {1, 2, 0};
        int i = 0, j = 0, k = 0;

        if (m[1][1] > m[0][0])
            i = 1;

        if (m[2][2] > m[i][i])
            i = 2;

        j = nxt[i];
        k = nxt[j];
        s = sqrtf((m[i][i] - (m[j][j] + m[k][k])) + 1.0f);

        q[i] = s * 0.5f;
        s = 0.5f / s;
        q[3] = (m[j][k] - m[k][j]) * s;
        q[j] = (m[i][j] + m[j][i]) * s;
        q[k] = (m[i][k] + m[k][i]) * s;
    }

    x = q[0], y = q[1], z = q[2], w = q[3];
}

/**
 * Method is used to extract axis angle from quaternion.
 * @param   axis is direction vector.
 * @param   degrees is angle.
 */
void Quaternion::toAxisAngle(Vector3D &axis, float &degrees)
{
    float sinHalfThetaSq = 1.0f - w * w;

    if (sinHalfThetaSq <= 0.0f)
    {
        axis.x = 1.0f, axis.y = axis.z = 0.0f;
        degrees = 0.0f;
    }
    else
    {
        float invSinHalfTheta = 1.0f / sqrtf(sinHalfThetaSq);

        axis.x = x * invSinHalfTheta;
        axis.y = y * invSinHalfTheta;
        axis.z = z * invSinHalfTheta;
        degrees = (2.0f * acosf(w)) * 180 / 3.14f;
    }
}

/**
 * Method is used to convert quaternion to a rotation matrix.
 * @return	rotation matrix.
 */
Matrix4 Quaternion::toMatrix4() const
{
    // Converts this quaternion to a rotation matrix.
    //
    //  | 1 - 2(y^2 + z^2)	2(xy + wz)			2(xz - wy)			0  |
    //  | 2(xy - wz)		1 - 2(x^2 + z^2)	2(yz + wx)			0  |
    //  | 2(xz + wy)		2(yz - wx)			1 - 2(x^2 + y^2)	0  |
    //  | 0					0					0					1  |

    float x2 = x + x; 
    float y2 = y + y; 
    float z2 = z + z;
    float xx = x * x2;
    float xy = x * y2;
    float xz = x * z2;
    float yy = y * y2;
    float yz = y * z2;
    float zz = z * z2;
    float wx = w * x2;
    float wy = w * y2;
    float wz = w * z2;

    Matrix4 m;

    m[0][0] = 1.0f - (yy + zz);
    m[0][1] = xy + wz;
    m[0][2] = xz - wy;
    m[0][3] = 0.0f;

    m[1][0] = xy - wz;
    m[1][1] = 1.0f - (xx + zz);
    m[1][2] = yz + wx;
    m[1][3] = 0.0f;

    m[2][0] = xz + wy;
    m[2][1] = yz - wx;
    m[2][2] = 1.0f - (xx + yy);
    m[2][3] = 0.0f;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;

    return m;
}
}