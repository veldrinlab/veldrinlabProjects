/**
 * File contains Vector3D class deinition.
 * @file    Vector3D.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0
 */

#include "Vector3D.hpp"

namespace Math 
{
/**
 * Constructor with initialization values.
 * @param   x is x value.
 * @param   y is y value.
 * @param   z is z value.
 */
Vector3D::Vector3D(const float x, const float y,const float z)
{
	this->x = x;
	this->y = y;
    this->z = z;
}

/**
 * Method is used to calculate cross product of vectors.
 * @param   p is first vector.
 * @param   q is second vector.
 * @return	vector that is cross prodcut of p and q.
 */
Vector3D Vector3D::cross(const Vector3D& p, const Vector3D& q)
{
    return Vector3D((p.y * q.z) - (p.z * q.y),
        (p.z * q.x) - (p.x * q.z),
        (p.x * q.y) - (p.y * q.x));
}

/**
 * Method is used to calculate distance between 2 points.
 * @param   pt1 is first vector.
 * @param   pt2 is second vector.
 * @return	vector that is distance between pt1 and pt2.
 */
float Vector3D::distance(const Vector3D& pt1, const Vector3D& pt2)
{
    return sqrtf(distanceSq(pt1, pt2));
}

/**
 * Method is used to calculate the squared distance between 2 points.
 * @param   pt1 is first vector.
 * @param   pt2 is second vector.
 * @return	vector that is the squared distance between pt1 and pt2.
 */
float Vector3D::distanceSq(const Vector3D& pt1, const Vector3D& pt2)
{
    return ((pt1.x - pt2.x) * (pt1.x - pt2.x))
        + ((pt1.y - pt2.y) * (pt1.y - pt2.y))
        + ((pt1.z - pt2.z) * (pt1.z - pt2.z));
}

/**
 * Method is used to calculate dot product of vectors.
 * @param   p is first vector.
 * @param   q is second vector.
 * @return	vector that is dot prodcut of p and q.
 */
float Vector3D::dot(const Vector3D& p, const Vector3D& q)
{
    return (p.x * q.x) + (p.y * q.y) + (p.z * q.z);
}


/**
 * Method is used to Linearly interpolates from 'p' to 'q' as t varies from 0 to 1
 * @param   p is fist vector.
 * @param   q is second vector.
 * @param   t is varies from 0 to 1.
 * @return	lineartlu interpolated vector.
 */
Vector3D Vector3D::lerp(const Vector3D& p, const Vector3D& q, const float t)
{
    return p + t * (q - p);
}

/**
 * Method used to perform Gram-Schmidt Orthogonalization on the 2 basis vectors to
 * turn them into orthonormal basis vectors.
 * @param   v1 is first vector.
 * @param   v2 is second vector.
 */
void Vector3D::orthogonalize(Vector3D& v1, Vector3D& v2)
{
    v2 = v2 - proj(v2, v1);
    v2.normalize();
}

/**
 * Method used to perform Gram-Schmidt Orthogonalization on the 3 basis vectors to
 * turn them into orthonormal basis vectors.
 * @param   v1 is first vector.
 * @param   v2 is second vector.
 * @param	v3 is third vector.
 */
void Vector3D::orthogonalize(Vector3D& v1, Vector3D& v2, Vector3D& v3)
{
    v2 = v2 - proj(v2, v1);
    v2.normalize();

    v3 = v3 - proj(v3, v1) - proj(v3, v2);
    v3.normalize();
}

/**
 * Method used to calculate projection of 'p' onto 'q'.
 * @param   p is first vector.
 * @param   q is second vector.
 * @return  calculated projection vector.
 */
Vector3D Vector3D::proj(const Vector3D& p, const Vector3D& q)
{
    float length =  q.magnitude();
    return (Vector3D::dot(p, q) / (length * length)) * q;
}

/**
 * Method used to calculate the component of 'p' perpendicular to 'q'.
 * @param   p is first vector.
 * @param   q is second vector.
 * @return  calculated perp vector.
 */
Vector3D Vector3D::perp(const Vector3D& p, const Vector3D& q)
{
    float length = q.magnitude();
    return p - ((Vector3D::dot(p, q) / (length * length)) * q);
}

/**
 * Method used to calculate reflection vector from entering ray direction 'i'
 * and surface normal 'n'.
 * @param   i is entering ray direction vector.
 * @param   n is surface normal vector.
 * @return  calculated reflect vector.
 */
Vector3D Vector3D::reflect(const Vector3D& i, const Vector3D& n)
{
    return i - 2.0f * Vector3D::proj(i, n);
}

/**
 * Class addition operator.
 * @param	rhs is second vector.
 * @return	result vector of addition.
 */
Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    x += rhs.x, y += rhs.y, z += rhs.z;
    return *this;
}

/**
 * Class equal operator.
 * @param   rhs is vector which we check if it is equal.
 * @return  true if vectors are equal.
 */
bool Vector3D::operator==(const Vector3D& rhs) const
{
    return (x == rhs.x && y ==  rhs.y
        && z == rhs.z);
}

/**
 * Class not equal operator.
 * @param   rhs is vector which we check if it is not equal.
 * @return  true if vectors are not equal.
 */
bool Vector3D::operator!=(const Vector3D& rhs) const
{
    return !(*this == rhs);
}

/**
 * Class substraction operator.
 * @param	rhs is second vector.
 * @return	result vector of substraction.
 */
Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    x -= rhs.x, y -= rhs.y, z -= rhs.z;
    return *this;
}

/**
 * Class multiply by scalar operator.
 * @param	scalar is scalar
 * @return	result vector of multiply by scalar
 */
Vector3D& Vector3D::operator*=(const float scalar)
{
    x *= scalar, y *= scalar, z *= scalar;
    return *this;
}

/**
 * Class divide by scalar operator.
 * @param	scalar is scalar
 * @return	result vector of divide by scalar
 */
Vector3D& Vector3D::operator/=(const float scalar)
{
    x /= scalar, y /= scalar, z /= scalar;
    return *this;
}

/**
 * Class addition operator.
 * @param	rhs is second vector.
 * @return	result vector of addition.
 */
Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
    Vector3D temp(*this);
    temp += rhs;
    return temp;
}

/**
 * Class substraction operator.
 * @param	rhs is second vector.
 * @return	result vector of substraction.
 */
Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
    Vector3D temp(*this);
    temp -= rhs;
    return temp;
}

/**
 * Class multiply by scalar operator.
 * @param	scalar is scalar
 * @return	result vector of multiply by scalar
 */
Vector3D Vector3D::operator*(const float scalar) const
{
    return Vector3D(x * scalar, y * scalar, z * scalar);    
}

/**
 * Class divide by scalar operator.
 * @param	scalar is scalar
 * @return	result vector of divide by scalar
 */
Vector3D Vector3D::operator/(const float scalar) const
{
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

/**
 * Method used to calculate vector magnitude.
 * @return	calculated magnitude value.
 */
float Vector3D::magnitude() const
{
    return sqrtf((x * x) + (y * y) + (z * z));
}

/**
 * Method used to calculate squared vector magnitude.
 * @return	calculated magnitude value.
 */
float Vector3D::magnitudeSq() const
{
    return (x * x) + (y * y) + (z * z);
}

/**
 * Method used to inverse vector.
 * @return	inverted vector.
 */
Vector3D Vector3D::inverse() const
{
    return Vector3D(-x, -y, -z);
}

/**
 * Method used to normalize vector.
 */
void Vector3D::normalize()
{
    float invMag = 1.0f / magnitude();
    x *= invMag, y *= invMag, z *= invMag;
}

/**
 * Method used to set vector values.
 * @param   x is x value.
 * @param   y is y value.
 * @param   z is z value.
 */
void Vector3D::set(const float x,const float y,const float z)
{
	this->x = x;
    this->y = y;
    this->z = z;
}

/**
 * Class operator used to multiply scalar by vector.
 * @param   lhs is scalar.
 * @param   rhs is vector.
 * @return  result of multiply.
 */
Vector3D operator*(const float lhs, const Vector3D& rhs)
{
    return Vector3D(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

/**
 * Class substraction operator.
 * @param   v is second vector. 
 * @return  result of substraction.
 */
Vector3D operator-(const Vector3D& v)
{
    return Vector3D(-v.x, -v.y, -v.z);
}
}