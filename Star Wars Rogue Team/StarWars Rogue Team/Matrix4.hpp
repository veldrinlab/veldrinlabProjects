/**
 * File contains declaration of Matrix class.
 * @file    Matrix4.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0
 */

#ifndef MATRIX4_HPP
#define MATRIX4_HPP

#include "Vector3D.hpp"

namespace math
{

/**
 * Matirx4 class represents homogeneous row-major 4x4 matrix class. Matirx4 class is used Camera class to make
 * transformation of Scene model and projection.
 * @remarks
 */
	class Matrix4
	{
	private:
		float matrix[4][4];

	public:
		static const Matrix4 IDENTITY;

		Matrix4();
		Matrix4(const float m11,const float m12,const float m13,const float m14,
		     const float m21,const float m22,const float m23,const float m24,
			 const float m31,const float m32,const float m33,const float m34,
		     const float m41,const float m42,const float m43,const float m44);
		~Matrix4();

		static Vector3D multiply(const Vector3D& lhs, const Matrix4& rhs);

		float *operator[](const int row);
		const float *operator[](const int row) const;
		bool operator==(const Matrix4& rhs) const;
		bool operator!=(const Matrix4& rhs) const;

		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(const Matrix4& rhs);
		Matrix4& operator*=(const float scalar);
		Matrix4& operator/=(const float scalar);
		Matrix4 operator+(const Matrix4& rhs) const;
		Matrix4 operator-(const Matrix4& rhs) const;
		Matrix4 operator*(const Matrix4& rhs) const;
		Matrix4 operator*(const float scalar) const;
		Matrix4 operator/(const float scalar) const;

	    void fromAxes(const Vector3D& x, const Vector3D& y, const Vector3D& z);
		void fromAxesTransposed(const Vector3D& x, const Vector3D& y, const Vector3D& z);
		void fromHeadPitchRoll(float headDegrees, float pitchDegrees, float rollDegrees);
		void identity();
		void rotate(const Vector3D& axis,float degrees);
		void scale(const float sx,const float sy,const float sz);
		void toAxes(Vector3D& x, Vector3D& y, Vector3D& z) const;
		void toAxesTransposed(Vector3D& x, Vector3D& y, Vector3D& z) const;
		void toHeadPitchRoll(float& headDegrees, float& pitchDegrees, float& rollDegrees) const;
		void translate(const float tx,const  float ty,const  float tz);  
	};
}	
#endif 

