#pragma once

// @brief: Vector, Matrix

template <class T>
class Vector2 
{
public:
	T x;
	T y;

	Vector2(T x, T y) :
		x(x), y(y) {}

	void operator+(const Vector2& vec2)
	{
		this->x += vec2.x;
		this->y += vec2.y;
	}

	void operator-(const Vector2& vec2)
	{
		this->x -= vec2.x;
		this->y -= vec2.y;
	}

	void operator*(const T num)
	{
		this->x *= num;
		this->y *= num;
	}
	// no division for safety

};


template <class T>
class Vector 
{
public:
	T x;
	T y;
	T z;

	Vector(T x, T y, T z) :
		x(x), y(y), z(z) {}

	void operator+(const Vector& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
	}

	void operator-(const Vector& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
	}

	void operator*(const T num)
	{
		this->x *= num;
		this->y *= num;
		this->z *= num;
	}
	// no division for safety

};


template <class T>
class Vector3 : public Vector<T>
{
};



typedef Vector2<float> vec2;
typedef Vector2<int> ivec2;
typedef Vector<float> vec3;
typedef Vector<int> ivec3;
