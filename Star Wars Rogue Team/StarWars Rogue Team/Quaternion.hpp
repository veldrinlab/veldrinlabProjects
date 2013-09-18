/**
 * File contains declaration of Quaternion class.
 * @file    Quaternion.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-20
 * @version 1.0
 */

#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Vector3D.hpp"
#include "Matrix4.hpp"

namespace math 
{
/**
 * Class represents Quaternion class used in Camera class to represent rotation and to avoid Gimbal Lock problem,
 * which occurs when Euler angles are used to implement Camera roatation.
 * @remarks 
 */
	class Quaternion
	{
	public:
		static const Quaternion IDENTITY;

		float w;
		float x;
		float y;
		float z;

		Quaternion();
		Quaternion(const float w, float x, float y, float z);
		Quaternion(float headDegrees, float pitchDegrees, float rollDegrees);
		Quaternion(const Vector3D& axis, float degrees);
		Quaternion(const Matrix4& m);
		~Quaternion();

		bool operator==(const Quaternion& rhs) const;
		bool operator!=(const Quaternion& rhs) const;

		Quaternion &operator+=(const Quaternion& rhs);
		Quaternion &operator-=(const Quaternion& rhs);
		Quaternion &operator*=(const Quaternion& rhs);
		Quaternion &operator*=(const float scalar);
		Quaternion &operator/=(const float scalar);
		Quaternion operator+(const Quaternion& rhs) const;
		Quaternion operator-(const Quaternion& rhs) const;
		Quaternion operator*(const Quaternion& rhs) const;
		Quaternion operator*(const float scalar) const;
		Quaternion operator/(const float scalar) const;

		Quaternion conjugate() const;
		void fromAxisAngle(const Vector3D& axis, float degrees);
		void fromHeadPitchRoll(float headDegrees, float pitchDegrees, float rollDegrees);
		void fromMatrix(const Matrix4& m);
		void identity();
		Quaternion inverse() const;
		float magnitude() const;
		void normalize();
		void set(const float w, const float x, const float y, const float z);
		void toAxisAngle(Vector3D& axis, float& degrees);
		void toHeadPitchRoll(float& headDegrees, float& pitchDegrees, float& rollDegrees) const;
		Matrix4 toMatrix4() const;
	};
}
#endif
