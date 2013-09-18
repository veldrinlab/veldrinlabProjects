/**
 * File contains definition of one of the math class - Matrix4 class.
 * @file    Matrix4.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0 
 */

#include "Matrix4.hpp"

namespace Math 
{
/**
 * Definition of Matrix class static members that represents identiy 4x4 matrix.
 */
const Matrix4 Matrix4::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f,
                              0.0f, 1.0f, 0.0f, 0.0f,
                              0.0f, 0.0f, 1.0f, 0.0f,
                              0.0f, 0.0f, 0.0f, 1.0f);

/**
 * Default constructor, set all values to zero.
 */
Matrix4::Matrix4()
{
	int i = 0;
	int j = 0;
	for(; i < 4 && j < 4; ++i, ++j)
		matrix[i][j] = 0.0;
}

/**
 * Destructor, nothing to do.
 */
Matrix4::~Matrix4()
{

}

/**
 * Constructor with initialization values.
 * @param   m11 matrix row-major value.
 * @param   m12 matrix row-major value.
 * @param   m13 matrix row-major value.
 * @param   m14 matrix row-major value.
 * @param   m21 matrix row-major value.
 * @param   m22 matrix row-major value.
 * @param   m23 matrix row-major value.
 * @param   m24 matrix row-major value.
 * @param   m31 matrix row-major value.
 * @param   m32 matrix row-major value.
 * @param   m33 matrix row-major value.
 * @param   m34 matrix row-major value.
 * @param   m41 matrix row-major value.
 * @param   m42 matrix row-major value.
 * @param   m43 matrix row-major value.
 * @param   m44 matrix row-major value.
 */
Matrix4::Matrix4(const float m11,const float m12,const float m13,const float m14,
                      const float m21,const float m22,const float m23,const float m24,
                      const float m31,const float m32,const float m33,const float m34,
                      const float m41,const float m42,const float m43,const float m44)
{
    matrix[0][0] = m11, matrix[0][1] = m12, matrix[0][2] = m13, matrix[0][3] = m14;
    matrix[1][0] = m21, matrix[1][1] = m22, matrix[1][2] = m23, matrix[1][3] = m24;
    matrix[2][0] = m31, matrix[2][1] = m32, matrix[2][2] = m33, matrix[2][3] = m34;
    matrix[3][0] = m41, matrix[3][1] = m42, matrix[3][2] = m43, matrix[3][3] = m44;
}

/**
 * Static method used to multiply vector by matrix.
 * @param   lhs is vector.
 * @param   rhs is matrix.
 * @return	calucalted result vector.
 */
Vector3D Matrix4::multiply(const Vector3D &lhs, const Matrix4 &rhs)
{
    return Vector3D((lhs.x * rhs.matrix[0][0]) + (lhs.y * rhs.matrix[1][0]) + (lhs.z * rhs.matrix[2][0]),
        (lhs.x * rhs.matrix[0][1]) + (lhs.y * rhs.matrix[1][1]) + (lhs.z * rhs.matrix[2][1]),
        (lhs.x * rhs.matrix[0][2]) + (lhs.y * rhs.matrix[1][2]) + (lhs.z * rhs.matrix[2][2]));
}

/**
 * Class indexer operator.
 * @param	row is matrix row which we can get to.
 * @return	indexing matrix row.
 */
float* Matrix4::operator[](const int row)
{
    return matrix[row];
}

/**
 * Class indexer operator.
 * @param	row is matrix row which we can get to.
 * @return	const indexing matrix row.
 */
const float* Matrix4::operator[](const int row) const
{
    return matrix[row];
}

/**
 * Class equal operator.
 * @param   rhs is matrix which we check if it is equal.
 * @return  true if matrixes are equal.
 */
bool Matrix4::operator==(const Matrix4 &rhs) const
{
    return (matrix[0][0] == rhs.matrix[0][0]
        && matrix[0][1] == rhs.matrix[0][1]
        && matrix[0][2] == rhs.matrix[0][2]
        && matrix[0][3] == rhs.matrix[0][3]
        && matrix[1][0] == rhs.matrix[1][0]
        && matrix[1][1] == rhs.matrix[1][1]
        && matrix[1][2] == rhs.matrix[1][2]
        && matrix[1][3] == rhs.matrix[1][3]
        && matrix[2][0] == rhs.matrix[2][0]
        && matrix[2][1] == rhs.matrix[2][1]
        && matrix[2][2] == rhs.matrix[2][2]
        && matrix[2][3] == rhs.matrix[2][3]
        && matrix[3][0] == rhs.matrix[3][0]
        && matrix[3][1] == rhs.matrix[3][1]
        && matrix[3][2] == rhs.matrix[3][2]
        && matrix[3][3] == rhs.matrix[3][3]);
}

/**
 * Class not-equal operator.
 * @param   rhs is matrix which we check if it is no equal.
 * @return  true if matrixes are not equal.
 */
bool Matrix4::operator!=(const Matrix4 &rhs) const
{
    return !(*this == rhs);
}

/**
 * Class matrix to matrix addition operator.
 * @param   rhs is second matrix.
 * @return  matrix that is result of addition operation.
 */
Matrix4& Matrix4::operator+=(const Matrix4 &rhs)
{
    matrix[0][0] += rhs.matrix[0][0], matrix[0][1] += rhs.matrix[0][1], matrix[0][2] += rhs.matrix[0][2], matrix[0][3] += rhs.matrix[0][3];
    matrix[1][0] += rhs.matrix[1][0], matrix[1][1] += rhs.matrix[1][1], matrix[1][2] += rhs.matrix[1][2], matrix[1][3] += rhs.matrix[1][3];
    matrix[2][0] += rhs.matrix[2][0], matrix[2][1] += rhs.matrix[2][1], matrix[2][2] += rhs.matrix[2][2], matrix[2][3] += rhs.matrix[2][3];
    matrix[3][0] += rhs.matrix[3][0], matrix[3][1] += rhs.matrix[3][1], matrix[3][2] += rhs.matrix[3][2], matrix[3][3] += rhs.matrix[3][3];
    return *this;
}

/**
 * Class matrix from matrix substraction operator.
 * @param   rhs is second matrix.
 * @return  matrix that is result of substraction operation.
 */
Matrix4& Matrix4::operator-=(const Matrix4 &rhs)
{
    matrix[0][0] -= rhs.matrix[0][0], matrix[0][1] -= rhs.matrix[0][1], matrix[0][2] -= rhs.matrix[0][2], matrix[0][3] -= rhs.matrix[0][3];
    matrix[1][0] -= rhs.matrix[1][0], matrix[1][1] -= rhs.matrix[1][1], matrix[1][2] -= rhs.matrix[1][2], matrix[1][3] -= rhs.matrix[1][3];
    matrix[2][0] -= rhs.matrix[2][0], matrix[2][1] -= rhs.matrix[2][1], matrix[2][2] -= rhs.matrix[2][2], matrix[2][3] -= rhs.matrix[2][3];
    matrix[3][0] -= rhs.matrix[3][0], matrix[3][1] -= rhs.matrix[3][1], matrix[3][2] -= rhs.matrix[3][2], matrix[3][3] -= rhs.matrix[3][3];
    return *this;
}

/**
 * Class matrix by matrix multiply operator.
 * @param   rhs is second matrix.
 * @return  matrix that is result of multiply operation.
 */
Matrix4& Matrix4::operator*=(const Matrix4 &rhs)
{
    Matrix4 tmp;

    tmp.matrix[0][0] = (matrix[0][0] * rhs.matrix[0][0]) + (matrix[0][1] * rhs.matrix[1][0]) + (matrix[0][2] * rhs.matrix[2][0]) + (matrix[0][3] * rhs.matrix[3][0]);
    tmp.matrix[0][1] = (matrix[0][0] * rhs.matrix[0][1]) + (matrix[0][1] * rhs.matrix[1][1]) + (matrix[0][2] * rhs.matrix[2][1]) + (matrix[0][3] * rhs.matrix[3][1]);
    tmp.matrix[0][2] = (matrix[0][0] * rhs.matrix[0][2]) + (matrix[0][1] * rhs.matrix[1][2]) + (matrix[0][2] * rhs.matrix[2][2]) + (matrix[0][3] * rhs.matrix[3][2]);
    tmp.matrix[0][3] = (matrix[0][0] * rhs.matrix[0][3]) + (matrix[0][1] * rhs.matrix[1][3]) + (matrix[0][2] * rhs.matrix[2][3]) + (matrix[0][3] * rhs.matrix[3][3]);

    tmp.matrix[1][0] = (matrix[1][0] * rhs.matrix[0][0]) + (matrix[1][1] * rhs.matrix[1][0]) + (matrix[1][2] * rhs.matrix[2][0]) + (matrix[1][3] * rhs.matrix[3][0]);
    tmp.matrix[1][1] = (matrix[1][0] * rhs.matrix[0][1]) + (matrix[1][1] * rhs.matrix[1][1]) + (matrix[1][2] * rhs.matrix[2][1]) + (matrix[1][3] * rhs.matrix[3][1]);
    tmp.matrix[1][2] = (matrix[1][0] * rhs.matrix[0][2]) + (matrix[1][1] * rhs.matrix[1][2]) + (matrix[1][2] * rhs.matrix[2][2]) + (matrix[1][3] * rhs.matrix[3][2]);
    tmp.matrix[1][3] = (matrix[1][0] * rhs.matrix[0][3]) + (matrix[1][1] * rhs.matrix[1][3]) + (matrix[1][2] * rhs.matrix[2][3]) + (matrix[1][3] * rhs.matrix[3][3]);

    tmp.matrix[2][0] = (matrix[2][0] * rhs.matrix[0][0]) + (matrix[2][1] * rhs.matrix[1][0]) + (matrix[2][2] * rhs.matrix[2][0]) + (matrix[2][3] * rhs.matrix[3][0]);
    tmp.matrix[2][1] = (matrix[2][0] * rhs.matrix[0][1]) + (matrix[2][1] * rhs.matrix[1][1]) + (matrix[2][2] * rhs.matrix[2][1]) + (matrix[2][3] * rhs.matrix[3][1]);
    tmp.matrix[2][2] = (matrix[2][0] * rhs.matrix[0][2]) + (matrix[2][1] * rhs.matrix[1][2]) + (matrix[2][2] * rhs.matrix[2][2]) + (matrix[2][3] * rhs.matrix[3][2]);
    tmp.matrix[2][3] = (matrix[2][0] * rhs.matrix[0][3]) + (matrix[2][1] * rhs.matrix[1][3]) + (matrix[2][2] * rhs.matrix[2][3]) + (matrix[2][3] * rhs.matrix[3][3]);

    tmp.matrix[3][0] = (matrix[3][0] * rhs.matrix[0][0]) + (matrix[3][1] * rhs.matrix[1][0]) + (matrix[3][2] * rhs.matrix[2][0]) + (matrix[3][3] * rhs.matrix[3][0]);
    tmp.matrix[3][1] = (matrix[3][0] * rhs.matrix[0][1]) + (matrix[3][1] * rhs.matrix[1][1]) + (matrix[3][2] * rhs.matrix[2][1]) + (matrix[3][3] * rhs.matrix[3][1]);
    tmp.matrix[3][2] = (matrix[3][0] * rhs.matrix[0][2]) + (matrix[3][1] * rhs.matrix[1][2]) + (matrix[3][2] * rhs.matrix[2][2]) + (matrix[3][3] * rhs.matrix[3][2]);
    tmp.matrix[3][3] = (matrix[3][0] * rhs.matrix[0][3]) + (matrix[3][1] * rhs.matrix[1][3]) + (matrix[3][2] * rhs.matrix[2][3]) + (matrix[3][3] * rhs.matrix[3][3]);

    *this = tmp;
    return *this;
}

/**
 * Class matrix by scalar multiply operator.
 * @param   scalar is scalar.
 * @return  matrix that is result of multiply operation.
 */
Matrix4& Matrix4::operator*=(const float scalar)
{
    matrix[0][0] *= scalar, matrix[0][1] *= scalar, matrix[0][2] *= scalar, matrix[0][3] *= scalar;
    matrix[1][0] *= scalar, matrix[1][1] *= scalar, matrix[1][2] *= scalar, matrix[1][3] *= scalar;
    matrix[2][0] *= scalar, matrix[2][1] *= scalar, matrix[2][2] *= scalar, matrix[2][3] *= scalar;
    matrix[3][0] *= scalar, matrix[3][1] *= scalar, matrix[3][2] *= scalar, matrix[3][3] *= scalar;
    return *this;
}

/**
 * Class matrix by skalar divide operator.
 * @param   scalar is scalar.
 * @return  matrix that is result of divide operation.
 */
Matrix4& Matrix4::operator/=(const float scalar)
{
    matrix[0][0] /= scalar, matrix[0][1] /= scalar, matrix[0][2] /= scalar, matrix[0][3] /= scalar;
    matrix[1][0] /= scalar, matrix[1][1] /= scalar, matrix[1][2] /= scalar, matrix[1][3] /= scalar;
    matrix[2][0] /= scalar, matrix[2][1] /= scalar, matrix[2][2] /= scalar, matrix[2][3] /= scalar;
    matrix[3][0] /= scalar, matrix[3][1] /= scalar, matrix[3][2] /= scalar, matrix[3][3] /= scalar;
    return *this;
}

/**
 * Class matrix addition operator.
 * @param   rhs is matrix to add.
 * @return  matrix that is result of addition operation.
 */
Matrix4 Matrix4::operator+(const Matrix4 &rhs) const
{
    Matrix4 tmp(*this);
    tmp += rhs;
    return tmp;
}

/**
 * Class matrix substraction operator.
 * @param   rhs is matrix to substract.
 * @return  matrix that is result of substraction operation.
 */
Matrix4 Matrix4::operator-(const Matrix4 &rhs) const
{
    Matrix4 tmp(*this);
    tmp -= rhs;
    return tmp;
}

/**
 * Class matrix mutiply by matrix operator.
 * @param   rhs is matrix to multiply
 * @return  matrix that is result of multiply operation.
 */
Matrix4 Matrix4::operator*(const Matrix4 &rhs) const
{
    Matrix4 tmp(*this);
    tmp *= rhs;
    return tmp;
}

/**
 * Class matrix multiply by scalar operator.
 * @param   scalar is scalar.
 * @return  matrix that is result of mutiply operation.
 */
Matrix4 Matrix4::operator*(float scalar) const
{
    Matrix4 tmp(*this);
    tmp *= scalar;
    return tmp;
}

/**
 * Class matrix divide by scalar operator.
 * @param   scalar is scalar.
 * @return  matrix that is result of divide operation.
 */
Matrix4 Matrix4::operator/(float scalar) const
{
    Matrix4 tmp(*this);
    tmp /= scalar;
    return tmp;
}

/**
 * Method is used to create matrix from axis vectors.
 * @param   x is xAxis vector.
 * @param   y is yAxis vector.
 * @param   z is zAxis vector.
 */
void Matrix4::fromAxes(const Vector3D& x, const Vector3D& y, const Vector3D& z)
{
    matrix[0][0] = x.x,  matrix[0][1] = x.y,  matrix[0][2] = x.z,  matrix[0][3] = 0.0f;
    matrix[1][0] = y.x,  matrix[1][1] = y.y,  matrix[1][2] = y.z,  matrix[1][3] = 0.0f;
    matrix[2][0] = z.x,  matrix[2][1] = z.y,  matrix[2][2] = z.z,  matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f, matrix[3][1] = 0.0f, matrix[3][2] = 0.0f, matrix[3][3] = 1.0f;
}

/**
 * Method is used to create transponed matrix from axis vectors.
 * @param   x is xAxis vector.
 * @param   y is yAxis vector.
 * @param   z is zAxis vector.
 */
void Matrix4::fromAxesTransposed(const Vector3D& x, const Vector3D &y, const Vector3D& z)
{
    matrix[0][0] = x.x,  matrix[0][1] = y.x,  matrix[0][2] = z.x,  matrix[0][3] = 0.0f;
    matrix[1][0] = x.y,  matrix[1][1] = y.y,  matrix[1][2] = z.y,  matrix[1][3] = 0.0f;
    matrix[2][0] = x.z,  matrix[2][1] = y.z,  matrix[2][2] = z.z,  matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f, matrix[3][1] = 0.0f, matrix[3][2] = 0.0f, matrix[3][3] = 1.0f;
}

/**
 * Method is used to create identity matrix.
 */
void Matrix4::identity()
{
    matrix[0][0] = 1.0f, matrix[0][1] = 0.0f, matrix[0][2] = 0.0f, matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f, matrix[1][1] = 1.0f, matrix[1][2] = 0.0f, matrix[1][3] = 0.0f;
    matrix[2][0] = 0.0f, matrix[2][1] = 0.0f, matrix[2][2] = 1.0f, matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f, matrix[3][1] = 0.0f, matrix[3][2] = 0.0f, matrix[3][3] = 1.0f;
}

/**
 * Method is used to create axis vectors from matrix.
 * @param   x is new xAxis vector.
 * @param   y is new yAxis vector.
 * @param   z is new zAxis vector.
 */
void Matrix4::toAxes(Vector3D& x, Vector3D& y, Vector3D& z) const
{
	x.set(matrix[0][0], matrix[0][1], matrix[0][2]);
    y.set(matrix[1][0], matrix[1][1], matrix[1][2]);
    z.set(matrix[2][0], matrix[2][1], matrix[2][2]);
}

/**
 * Method is used to create axis vectors from transposed matrix.
 * @param   x is new xAxis vector.
 * @param   y is new yAxis vector.
 * @param   z is new zAxis vector.
 */
void Matrix4::toAxesTransposed(Vector3D& x, Vector3D& y, Vector3D& z) const
{
    x.set(matrix[0][0], matrix[1][0], matrix[2][0]);
    y.set(matrix[0][1], matrix[1][1], matrix[2][1]);
    z.set(matrix[0][2], matrix[1][2], matrix[2][2]);
}

/**
 * Method is used to construct a rotation matrix based on a Euler Transform.
 * @param   headDegrees is zAxis angle.
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle.
 */
void Matrix4::fromHeadPitchRoll(float headDegrees, float pitchDegrees, float rollDegrees)
{
    headDegrees = headDegrees * 3.14f / 180; 
    pitchDegrees = pitchDegrees * 3.14f / 180;
    rollDegrees = rollDegrees * 3.14f / 180;

    float cosH = cosf(headDegrees);
    float cosP = cosf(pitchDegrees);
    float cosR = cosf(rollDegrees);
    float sinH = sinf(headDegrees);
    float sinP = sinf(pitchDegrees);
    float sinR = sinf(rollDegrees);

    matrix[0][0] = cosR * cosH - sinR * sinP * sinH;
    matrix[0][1] = sinR * cosH + cosR * sinP * sinH;
    matrix[0][2] = -cosP * sinH;
    matrix[0][3] = 0.0f;

    matrix[1][0] = -sinR * cosP;
    matrix[1][1] = cosR * cosP;
    matrix[1][2] = sinP;
    matrix[1][3] = 0.0f;

    matrix[2][0] = cosR * sinH + sinR * sinP * cosH;
    matrix[2][1] = sinR * sinH - cosR * sinP * cosH;
    matrix[2][2] = cosP * cosH;
    matrix[2][3] = 0.0f;

    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

/**
 * Method is used to create a rotation matrix about the specified axis.The axis must be
 * a unit vector. The angle must be in degrees.
 * @param   axis  is axis vector.
 * @param   degrees is angle degrees.
 */
void Matrix4::rotate(const Vector3D& axis,float degrees)
{
    degrees = 3.14f * degrees / 180;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float c = cosf(degrees);
    float s = sinf(degrees);

    matrix[0][0] = (x * x) * (1.0f - c) + c;
    matrix[0][1] = (x * y) * (1.0f - c) - (z * s);
    matrix[0][2] = (x * z) * (1.0f - c) + (y * s);
    matrix[0][3] = 0.0f;

    matrix[1][0] = (y * x) * (1.0f - c) + (z * s);
    matrix[1][1] = (y * y) * (1.0f - c) + c;
    matrix[1][2] = (y * z) * (1.0f - c) - (x * s);
    matrix[1][3] = 0.0f;

    matrix[2][0] = (z * x) * (1.0f - c) - (y * s);
    matrix[2][1] = (z * y) * (1.0f - c) + (x * s);
    matrix[2][2] = (z * z) * (1.0f - c) + c;
    matrix[2][3] = 0.0f;

    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

/**
 * Method is used to create scaling matrix.
 * @param   sx is xAxis value.
 * @param   sy is yAxis value.
 * @param   sz is zAxis value.
 */
void Matrix4::scale(const float sx,const float sy,const float sz)
{
    matrix[0][0] = sx,   matrix[0][1] = 0.0f, matrix[0][2] = 0.0f, matrix[0][3] = 0.0f;
    matrix[1][0] = 0.0f, matrix[1][1] = sy,   matrix[1][2] = 0.0f, matrix[1][3] = 0.0f;
    matrix[2][0] = 0.0f, matrix[2][1] = 0.0f, matrix[2][2] = sz,   matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f, matrix[3][1] = 0.0f, matrix[3][2] = 0.0f, matrix[3][3] = 1.0f;
}

/**
 * Method is used to extract the Euler angles from a rotation matrix.
 * @param   headDegrees is zAxis angle.
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle.
 */
void Matrix4::toHeadPitchRoll(float& headDegrees, float& pitchDegrees, float& rollDegrees) const
{
    float thetaX = asinf(matrix[1][2]);
    float thetaY = 0.0f;
    float thetaZ = 0.0f;

    if (thetaX < 3.14f/2)
    {
        if (thetaX > -3.14f/2)
        {
            thetaZ = atan2f(-matrix[1][0], matrix[1][1]);
            thetaY = atan2f(-matrix[0][2], matrix[2][2]);
        }
        else
        {
            thetaZ = -atan2f(matrix[2][0], matrix[0][0]);
            thetaY = 0.0f;
        }
    }
    else
    {
        thetaZ = atan2f(matrix[2][0], matrix[0][0]);
        thetaY = 0.0f;
    }

    headDegrees = 180* thetaY / 3.14f;
    pitchDegrees = 180* thetaX / 3.14f;
    rollDegrees = 180* thetaZ / 3.14f;

}

/**
 * Method used to create translation matrix.
 * @param   tx is xAxis translation value.
 * @param   ty is yAxis translation value.
 * @param   tz is zAxis translation value.
 */
void Matrix4::translate(const float tx,const float ty,const float tz)
{
    matrix[0][0] = 1.0f, matrix[0][1] = 0.0f, matrix[0][2] = 0.0f, matrix[0][3] = tx;
    matrix[1][0] = 0.0f, matrix[1][1] = 1.0f, matrix[1][2] = 0.0f, matrix[1][3] = ty;
    matrix[2][0] = 0.0f, matrix[2][1] = 0.0f, matrix[2][2] = 1.0f, matrix[2][3] = tz;
    matrix[3][0] = 0.0f, matrix[3][1] = 0.0f, matrix[3][2] = 0.0f, matrix[3][3] = 1.0f;
}
}