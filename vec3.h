#pragma once
#include <math.h>

struct Vec3 {
	double x;
	double y;
	double z;

	Vec3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vec3(double x)
	{
		this->x = x;
		this->y = x;
		this->z = x;
	}
	Vec3()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	Vec3 operator -()
	{
		return Vec3(-x, -y, -z);
	}

	Vec3 operator*= (double p)
	{
		this->x *= p;
		this->y *= p;
		this->z *= p;
		return *this;
	}

	Vec3 operator /= (double p)
	{
		this->x /= p;
		this->y /= p;
		this->z /= p;
		return *this;
	}

	Vec3 operator+= (const Vec3& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	Vec3 operator-= (const Vec3& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	Vec3 operator- (const Vec3& vector)
	{
		Vec3 result;
		result.x = this->x - vector.x;
		result.y = this->y - vector.y;
		result.z = this->z - vector.z;
		return result;
	}

	Vec3 operator+ (const Vec3 vector)
	{
		Vec3 result;
		result.x = this->x + vector.x;
		result.y = this->y + vector.y;
		result.z = this->z + vector.z;
		return result;
	}

	Vec3 operator/ (double p)
	{
		Vec3 result;
		result.x = this->x / p;
		result.y = this->y / p;
		result.z = this->z / p;
		return result;
	}

	Vec3 sqrtVec()
	{
		return Vec3(sqrt(x), sqrt(y), sqrt(z));
	}

	double magnitude()
	{
		double magnitude = sqrt(x * x + y * y + z * z);
		return magnitude;
	}
};