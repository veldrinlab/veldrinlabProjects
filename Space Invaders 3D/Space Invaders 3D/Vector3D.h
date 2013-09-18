/**
 * File contains declaration of Vector3D class.
 * @file    Vector3D.h
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>

/**
 * Vector3D class represents three dimmension Vector object which is used in game math and physics calculations
 * like object position, velocity, acceleration or direction. 
 * @remarks
 */
class Vector3D
{
public:
    float x;
	float y;
	float z;

    static Vector3D cross(const Vector3D& p, const Vector3D& q);
    static float distance(const Vector3D& pt1, const Vector3D& pt2);
    static float distanceSq(const Vector3D& pt1, const Vector3D& pt2);  
    static float dot(const Vector3D& p, const Vector3D& q);
    static Vector3D lerp(const Vector3D& p, const Vector3D& q, const float t);
    static void orthogonalize(Vector3D& v1, Vector3D& v2);
    static void orthogonalize(Vector3D& v1, Vector3D& v2, Vector3D& v3);
    static Vector3D proj(const Vector3D& p, const Vector3D& q);
    static Vector3D perp(const Vector3D& p, const Vector3D& q);
    static Vector3D reflect(const Vector3D& i, const Vector3D& n);

    Vector3D() {}
    Vector3D(const float x,const float y,const float z);
    ~Vector3D() {}

    bool operator==(const Vector3D& rhs) const;
    bool operator!=(const Vector3D& rhs) const;

    Vector3D &operator+=(const Vector3D& rhs);
    Vector3D &operator-=(const Vector3D& rhs);
    Vector3D &operator*=(const float scalar);
    Vector3D &operator/=(const float scalar);
    Vector3D operator+(const Vector3D& rhs) const;
    Vector3D operator-(const Vector3D& rhs) const;
    Vector3D operator*(const float scalar) const;
    Vector3D operator/(const float scalar) const;

    float magnitude() const;
    float magnitudeSq() const;
    Vector3D inverse() const;
    void normalize();
    void set(const float x,const float y,const float z);
	friend Vector3D operator*(const float lhs, const Vector3D& rhs);
    friend Vector3D operator-(const Vector3D& v);
};
#endif
