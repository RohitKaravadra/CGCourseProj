﻿#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include "memory.h"
#define SQ(x) (x) * (x)
#define max(a,b)(a>b?a:b)
#define max_tri(a, b, c) ((a > b ? a : b) > c ? (a > b ? a : b) : c)
#define min(a,b)(a<b?a:b)
#define min_tri(a, b, c) ((a < b ? a : b) < c ? (a < b ? a : b) : c)

const float _near = 0.1;
const float _far = 100;

template<typename T>
static T lerp(const T a, const T b, float t)
{
	return a * (1.0f - t) + (b * t);
}

template <typename T>
T clamp(T value, T min, T max) {
	return (value < min) ? min : (value > max) ? max : value;
}

//float Dot(const Vec3& v1, const Vec3& v2)
//{
//	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
//}

//-------------------------------Vec2--------------------------------
class Vec2
{
public:
	union
	{
		float v[2];
		struct { float x, y; };
	};
	Vec2() {
		for (int i = 0; i < 2; i++) v[i] = 0.f;
	}
	Vec2(float _x, float _y) {
		v[0] = _x;
		v[1] = _y;
	}
	Vec2& operator+=(const Vec2& pVec)
	{
		v[0] += pVec.v[0];
		v[1] += pVec.v[1];
		return *this;
	}
	Vec2 operator*(const float val) const
	{
		return Vec2(v[0] * val, v[1] * val);
	}
	Vec2 operator-() const //?
	{
		return Vec2(-v[0], -v[1]);
	}
	Vec2 operator+(const Vec2& v)const { return Vec2(x + v.x, y + v.y); }
	Vec2 operator-(const Vec2& v)const { return Vec2(x - v.x, y - v.y); }
	Vec2 operator*(const Vec2& v)const { return Vec2(x * v.x, y * v.y); }

	float Length() const {
		return SQ(x) + SQ(y);
	}
	float squareLength() const {
		return sqrtf(SQ(x) + SQ(y));
	}
	Vec2 normalize()
	{
		float len = 1.0f / sqrtf(v[0] * v[0] + v[1] * v[1]);
		return Vec2(x * len, y * len);
	}
	float normalize_GetLength()
	{
		float length = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		float len = 1.0f / length;
		v[0] *= len; v[1] *= len; v[2] *= len;
		return length;
	}
	float dot(const Vec2& pVec) const
	{
		return v[0] * pVec.v[0] + v[1] * pVec.v[1];
	}
	float cross(const Vec2& v1)
	{
		return (v1.v[0] * v[1] - v1.v[1] * v[0]);
	}
};
static float cross_lefttop(const Vec2& v1, const Vec2& v2)
{
	return (v1.x * v2.y - v1.y * v2.x) * -1;
	//adjusting for Top-Left coordinates: negate the result
}
static float cross(const Vec2& v1, const Vec2& v2)
{
	return (v1.x * v2.y - v1.y * v2.x);
	//adjusting for Top-Left coordinates: negate the result
}

//-------------------------------Vec3--------------------------------
class Vec3
{
public:
	union
	{
		float v[3];
		struct { float x, y, z; };
	};
	Vec3() {
		for (int i = 0; i < 3; i++) v[i] = 0.f;
	}
	Vec3(float _x, float _y, float _z) {
		v[0] = _x;
		v[1] = _y;
		v[2] = _z;
	}
	Vec3 operator*(const float val) const
	{
		return Vec3(v[0] * val, v[1] * val, v[2] * val);
	}
	Vec3 operator-() const //?
	{
		return Vec3(-v[0], -v[1], -v[2]);
	}
	Vec3 operator+(const Vec3& v)const { return Vec3(x + v.x, y + v.y, z + v.z); }
	Vec3 operator-(const Vec3& v)const { return Vec3(x - v.x, y - v.y, z - v.z); }
	Vec3 operator*(const Vec3& v)const { return Vec3(x * v.x, y * v.y, z * v.z); }
	Vec3 operator/(const Vec3& v)const { return Vec3(x / v.x, y / v.y, z / v.z); }
	Vec3& operator+=(const Vec3& v) { x += v.x, y += v.y, z += v.z; return *this; }
	Vec3& operator-=(const Vec3& v) { x -= v.x, y -= v.y, z -= v.z; return *this; }
	Vec3& operator*=(const Vec3& v) { x *= v.x, y *= v.y, z *= v.z; return *this; }
	Vec3& operator/=(const Vec3& v) { x /= v.x, y /= v.y, z /= v.z; return *this; }
	Vec3& operator=(const Vec3& v) { x = v.x, y = v.y, z = v.z; return *this; }

	float Length() const {
		return SQ(x) + SQ(y) + SQ(z);
	}
	float squareLength() const {
		return sqrtf(SQ(x) + SQ(y) + SQ(z));
	}
	Vec3 normalize()
	{
		float len = 1.0f / sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		return Vec3(x * len, y * len, z * len);
	}

	float normalize_GetLength()
	{
		float length = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		float len = 1.0f / length;
		v[0] *= len; v[1] *= len; v[2] *= len;
		return length;
	}
	float dot(const Vec3& pVec) const
	{
		return v[0] * pVec.v[0] + v[1] * pVec.v[1] + v[2] * pVec.v[2];
	}
	Vec3 cross(const Vec3& v1)
	{
		return Vec3(v1.v[1] * v[2] - v1.v[2] * v[1],
			v1.v[2] * v[0] - v1.v[0] * v[2],
			v1.v[0] * v[1] - v1.v[1] * v[0]);
	}
	Vec3 Max(const Vec3& v1, const Vec3& v2)
	{
		return Vec3(max(v1.v[0], v2.v[0]),
			max(v1.v[1], v2.v[1]),
			max(v1.v[2], v2.v[2]));
	}

	float Max() const
	{
		return max(x, max(y, z));
	}

};
static Vec3 cross(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
		v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
		v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}
Vec3 Max(const Vec3& v1, const Vec3& v2)
{
	return Vec3(max(v1.v[0], v2.v[0]),
		max(v1.v[1], v2.v[1]),
		max(v1.v[2], v2.v[2]));
}
float Max(Vec3& v)
{
	return max(v.x, max(v.y, v.z));
}
float dot(const Vec3& v1, const Vec3& v2)
{
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
}
//-------------------------------Vec4--------------------------------
class Vec4
{
public:
	union
	{
		float v[4];
		struct { float x, y, z, w; };
	};
	Vec4() {
		for (int i = 0; i < 4; i++) v[i] = 0.f;
	}
	Vec4(float _x, float _y, float _z, float _w) {
		v[0] = _x;
		v[1] = _y;
		v[2] = _z;
		v[3] = _w;
	}
	Vec4 operator-() const //?
	{
		return Vec4(-v[0], -v[1], -v[2], -v[3]);
	}
	Vec4 operator+(const Vec4& v)const { return Vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
	Vec4 operator-(const Vec4& v)const { return Vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
	Vec4 operator*(const Vec4& v)const { return Vec4(x * v.x, y * v.y, z * v.z, w * v.w); }
	Vec4 operator/(const Vec4& v)const { return Vec4(x / v.x, y / v.y, z / v.z, w / v.w); }
	Vec4 operator/(const float val)const { return Vec4(x / val, y / val, z / val, w / val); }
	Vec4& operator+=(const Vec4& v) { x += v.x, y += v.y, z += v.z, w += v.w; return *this; }
	Vec4& operator-=(const Vec4& v) { x -= v.x, y -= v.y, z -= v.z, w -= v.w; return *this; }
	Vec4& operator*=(const Vec4& v) { x *= v.x, y *= v.y, z *= v.z, w *= v.w; return *this; }
	Vec4& operator/=(const Vec4& v) { x /= v.x, y /= v.y, z /= v.z, w /= v.w; return *this; }
	Vec4& operator/=(const float val) { x /= val, y /= val, z /= val, w /= val; return *this; }

	float Length() const {
		return SQ(x) + SQ(y) + SQ(z) + SQ(w);
	}
	float squareLength() const {
		return sqrtf(SQ(x) + SQ(y) + SQ(z) + SQ(w));
	}
	Vec4 normalize(void)
	{
		float len = 1.0f / sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
		return Vec4(x * len, y * len, z * len, w * len);
	}
	//======================================
	//float normalize_GetLength()
	//{
	//	float length = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	//	float len = 1.0f / length;
	//	v[0] *= len; v[1] *= len; v[2] *= len;
	//	return length;
	//}
	//float Dot(const Vec3& pVec) const
	//{
	//	return v[0] * pVec.v[0] + v[1] * pVec.v[1] + v[2] * pVec.v[2];
	//}
	//Vec3 Cross(const Vec3& v1)
	//{
	//	return Vec3(v1.v[1] * v[2] - v1.v[2] * v[1],
	//		v1.v[2] * v[0] - v1.v[0] * v[2],
	//		v1.v[0] * v[1] - v1.v[1] * v[0]);
	//}

};

//-------------------------------HomoVec--------------------------------
class HomoVec : public Vec4 {
public:
	HomoVec(float _x, float _y, float _z, float _w) {
		v[0] = _x;
		v[1] = _y;
		v[2] = _z;
		v[3] = _w;
	}
	HomoVec(Vec4 _v) {
		v[0] = _v.x;
		v[1] = _v.y;
		v[2] = _v.z;
		v[3] = _v.w;
	}
	void divisionW() {
		if (w != 0) {
			x /= w; //x_ndc
			y /= w; //y_ndc
			z /= w; //z_ndc
			w = 1.0f;
			//std::cout << "After division w:" << "x = " << x << "y = " << y << "z = " <<z<< std::endl;
		}
		else {
			throw std::runtime_error("Division by zero: w cannot be zero.");
		}
	}
	HomoVec& operator=(const Vec4 v) { x = v.x, y = v.y, z = v.z, w = v.w; return *this; }
};

//-------------------------------Matrix--------------------------------
class Matrix
{
public:
	union
	{
		float a[4][4];
		float m[16];
	};
	Matrix(float* otherM) {
		memcpy(&m, otherM, 16 * sizeof(float));
	}
	Matrix() {
		a[0][0] = 0.f;
		a[0][1] = 0.f;
		a[0][2] = 0.f;
		a[0][3] = 0.f;
		a[1][0] = 0.f;
		a[1][1] = 0.f;
		a[1][2] = 0.f;
		a[1][3] = 0.f;
		a[2][0] = 0.f;
		a[2][1] = 0.f;
		a[2][2] = 0.f;
		a[2][3] = 0.f;
		a[3][0] = 0.f;
		a[3][1] = 0.f;
		a[3][2] = 0.f;
		a[3][3] = 0.f;
	}

	Matrix(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
		a[0][0] = m00;
		a[0][1] = m01;
		a[0][2] = m02;
		a[0][3] = m03;
		a[1][0] = m10;
		a[1][1] = m11;
		a[1][2] = m12;
		a[1][3] = m13;
		a[2][0] = m20;
		a[2][1] = m21;
		a[2][2] = m22;
		a[2][3] = m23;
		a[3][0] = m30;
		a[3][1] = m31;
		a[3][2] = m32;
		a[3][3] = m33;
	}
	void identity() {
		memset(m, 0, 16 * sizeof(float));
		m[0] = 1.0f;
		m[5] = 1.0f;
		m[10] = 1.0f;
		m[15] = 1.0f;
	}
	float& operator[](int index) {
		return m[index];
	}
	Matrix operator*(const Matrix& matrix)
	{
		return mul(matrix);
	}

	static Matrix worldMatrix(const Vec3& v_t, const Vec3& v_s, float theta_x, float theta_y, float theta_z) {
		Matrix translation = translation.translation(v_t);
		Matrix scaling = scaling.scaling(v_s);
		Matrix rotateX = rotateX.rotateX(theta_x);
		Matrix rotateY = rotateY.rotateY(theta_y);
		Matrix rotateZ = rotateZ.rotateZ(theta_z);
		Matrix rotation = rotateX * rotateY * rotateZ;
		return(scaling * rotation * translation);
	}

	//---------------trans scale rotate----------------------------------------------
	static Matrix translation(const Vec3& v) {
		Matrix mat;
		mat.identity();  // Set up an identity matrix
		mat.a[0][3] = v.x;
		mat.a[1][3] = v.y;
		mat.a[2][3] = v.z;
		return mat;
	}
	static Matrix scaling(const Vec3& v) {
		Matrix mat;
		mat.identity();  // Set up an identity matrix
		mat.m[0] = v.x;
		mat.m[5] = v.y;
		mat.m[10] = v.z;
		return mat;
	}
	static Matrix rotateX(float theta) {
		Matrix mat;
		mat.identity();  // Set up an identity matrix

		float ct = cosf(theta);
		float st = sinf(theta);

		// Fill in rotation matrix for X axis
		mat.a[1][1] = ct;
		mat.a[1][2] = -st;
		mat.a[2][1] = st;
		mat.a[2][2] = ct;

		return mat;
	}

	static Matrix rotateY(float theta) {
		Matrix mat;
		mat.identity();  // Set up an identity matrix

		float ct = cosf(theta);
		float st = sinf(theta);

		// Fill in rotation matrix for Y axis
		mat.a[0][0] = ct;
		mat.a[0][2] = st;
		mat.a[2][0] = -st;
		mat.a[2][2] = ct;

		return mat;
	}

	static Matrix rotateZ(float theta) {
		Matrix mat;
		mat.identity();  // Set up an identity matrix

		float ct = cosf(theta);
		float st = sinf(theta);

		// Fill in rotation matrix for Z axis
		mat.a[0][0] = ct;
		mat.a[0][1] = -st;
		mat.a[1][0] = st;
		mat.a[1][1] = ct;

		return mat;
	}
	//----------------------------mul---------------------------------------------
	Vec3 mulPoint(const Vec3& v)
	{
		return Vec3(
			(v.x * m[0] + v.y * m[1] + v.z * m[2]) + m[3],
			(v.x * m[4] + v.y * m[5] + v.z * m[6]) + m[7],
			(v.x * m[8] + v.y * m[9] + v.z * m[10]) + m[11]);
	}

	Vec3 mulVec(const Vec3& v)
	{
		return Vec3(
			(v.x * m[0] + v.y * m[1] + v.z * m[2]),
			(v.x * m[4] + v.y * m[5] + v.z * m[6]),
			(v.x * m[8] + v.y * m[9] + v.z * m[10]));
	}
	Vec4 mulVec(const Vec4& v)
	{
		return Vec4(
			(v.x * m[0] + v.y * m[1] + v.z * m[2] + v.w * m[3]),
			(v.x * m[4] + v.y * m[5] + v.z * m[6] + v.w * m[7]),
			(v.x * m[8] + v.y * m[9] + v.z * m[10] + v.w * m[11]),
			(v.x * m[12] + v.y * m[13] + v.z * m[14] + v.w * m[15]));
	}
	Matrix mul(const Matrix& matrix) const
	{
		Matrix ret;
		ret.m[0] = m[0] * matrix.m[0] + m[4] * matrix.m[1] + m[8] * matrix.m[2] + m[12] * matrix.m[3];
		ret.m[1] = m[1] * matrix.m[0] + m[5] * matrix.m[1] + m[9] * matrix.m[2] + m[13] * matrix.m[3];
		ret.m[2] = m[2] * matrix.m[0] + m[6] * matrix.m[1] + m[10] * matrix.m[2] + m[14] * matrix.m[3];
		ret.m[3] = m[3] * matrix.m[0] + m[7] * matrix.m[1] + m[11] * matrix.m[2] + m[15] * matrix.m[3];
		ret.m[4] = m[0] * matrix.m[4] + m[4] * matrix.m[5] + m[8] * matrix.m[6] + m[12] * matrix.m[7];
		ret.m[5] = m[1] * matrix.m[4] + m[5] * matrix.m[5] + m[9] * matrix.m[6] + m[13] * matrix.m[7];
		ret.m[6] = m[2] * matrix.m[4] + m[6] * matrix.m[5] + m[10] * matrix.m[6] + m[14] * matrix.m[7];
		ret.m[7] = m[3] * matrix.m[4] + m[7] * matrix.m[5] + m[11] * matrix.m[6] + m[15] * matrix.m[7];
		ret.m[8] = m[0] * matrix.m[8] + m[4] * matrix.m[9] + m[8] * matrix.m[10] + m[12] * matrix.m[11];
		ret.m[9] = m[1] * matrix.m[8] + m[5] * matrix.m[9] + m[9] * matrix.m[10] + m[13] * matrix.m[11];
		ret.m[10] = m[2] * matrix.m[8] + m[6] * matrix.m[9] + m[10] * matrix.m[10] + m[14] * matrix.m[11];
		ret.m[11] = m[3] * matrix.m[8] + m[7] * matrix.m[9] + m[11] * matrix.m[10] + m[15] * matrix.m[11];
		ret.m[12] = m[0] * matrix.m[12] + m[4] * matrix.m[13] + m[8] * matrix.m[14] + m[12] * matrix.m[15];
		ret.m[13] = m[1] * matrix.m[12] + m[5] * matrix.m[13] + m[9] * matrix.m[14] + m[13] * matrix.m[15];
		ret.m[14] = m[2] * matrix.m[12] + m[6] * matrix.m[13] + m[10] * matrix.m[14] + m[14] * matrix.m[15];
		ret.m[15] = m[3] * matrix.m[12] + m[7] * matrix.m[13] + m[11] * matrix.m[14] + m[15] * matrix.m[15];
		return ret;
	}

	Matrix invert()
	{
		Matrix inv;
		inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
		inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
		inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
		inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
		inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
		inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
		inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
		inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
		inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
		inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
		inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
		inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
		inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
		inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
		inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
		inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];
		float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
		if (det == 0) {
			// Handle this case
			throw std::runtime_error("Matrix is singular and cannot be inverted.");
		}
		det = 1.0 / det;
		for (int i = 0; i < 16; i++) {
			inv[i] = inv[i] * det;
		}
		return inv;
	}

	void perspectiveProjection(float aspect, float tan) {
		m[0] = 1 / (aspect * tan);
		m[5] = 1 / tan;
		m[10] = -_far / (_far - _near);
		m[11] = -_far * _near / (_far - _near);
		m[14] = -1;
		m[15] = 0;
	}

	Matrix lookAtMat(const Vec3& from, const Vec3& to, const Vec3& up) {
		Matrix lookat;
		Vec3 dir, right, up_;
		dir = from - to;
		dir = dir.normalize();
		right = cross(up, dir).normalize(); //normalize????????????????
		up_ = cross(dir, right).normalize(); //????????????????
		// rotation
		lookat.m[0] = right.x;
		lookat.m[1] = right.y;
		lookat.m[2] = right.z;

		lookat.m[4] = up_.x;
		lookat.m[5] = up_.y;
		lookat.m[6] = up_.z;

		lookat.m[8] = dir.x;
		lookat.m[9] = dir.y;
		lookat.m[10] = dir.z;
		lookat.m[15] = 1.0f;

		// transltion
		lookat.m[3] = -from.dot(right);
		lookat.m[7] = -from.dot(up_);
		lookat.m[11] = -from.dot(dir);
		//std::cout << "from " << from.x << " " << from.y << " " << from.z << std::endl;
		//std::cout<< "dir " << dir.x << " " << dir.y << " " << dir.z << std::endl;
		//std::cout << from.dot(dir) << std::endl;

		return lookat;
	}
	void print() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
};

class Spherical {
	//float theta;
	//float phi;
	// r == 1
	// (x,y,z) to (θ, φ)
	//Spherical(float _theta, float _phi) :theta(_theta), phi(_phi){}
	void cartesianToSpherical(float x, float y, float z, float& theta, float& phi) {
		// z-up (shading)
		theta = acos(z / 1.f);
		phi = atan(y / x);
	}
	// (θ, φ) to (x,y,z)
	void sphericalToCartesian(float theta, float phi, float& x, float& y, float& z) {
		x = sinf(theta) * cosf(phi);
		y = sinf(theta) * sinf(phi);
		z = cosf(theta);
	}
};

class Quaternion {
public:
	union {
		struct {
			// q=a+bi+cj+dk
			float a;
			float b;
			float c;
			float d;
		};
		float q[4];
	};
	// Constructor
	Quaternion(float _a, float _b, float _c, float _d) : a(_a), b(_b), c(_c), d(_d) {}

	// Magnitude of the quaternion
	float magnitude() const {
		return sqrt(SQ(a) + SQ(b) + SQ(c) + SQ(d));
	}

	// Normalize the quaternion
	void normalize() {
		float mag = magnitude();
		if (mag > 0) {
			a /= mag;
			b /= mag;
			c /= mag;
			d /= mag;
		}
	}

	// Conjugate of the quaternion
	Quaternion conjugate() const {
		return Quaternion(a, -b, -c, -d);
	}

	// Inverse of the quaternion (only valid for unit quaternions)
	Quaternion inverse() const {
		float mag = magnitude();
		// mag == 1?
		return Quaternion(a / mag, -b / mag, -c / mag, -d / mag);
	}

	// Slerp (Spherical Linear Interpolation)
	static Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t) {
		// Compute the cosine of the angle between the two quaternions
		float cosTheta = q1.a * q2.a + q1.b * q2.b + q1.c * q2.c + q1.d * q2.d;

		// If cosTheta is negative, invert one quaternion to reduce spinning
		Quaternion q2Modified = (cosTheta < 0) ? Quaternion(-q2.a, -q2.b, -q2.c, -q2.d) : q2;
		cosTheta = fabs(cosTheta);

		//// Linear interpolation for small angles
		//if (cosTheta > 0.95f) {
		//	return Quaternion(
		//		(1 - t) * q1.w + t * q2Modified.w,
		//		(1 - t) * q1.x + t * q2Modified.x,
		//		(1 - t) * q1.y + t * q2Modified.y,
		//		(1 - t) * q1.z + t * q2Modified.z
		//	).normalized();
		//}

		// Compute the angle and sin values
		float angle = acos(cosTheta);
		float sinTheta = sqrt(1.0f - SQ(cosTheta));

		// Compute the weights
		float w1 = sin((1 - t) * angle) / sinTheta;
		float w2 = sin(t * angle) / sinTheta;

		return Quaternion(
			w1 * q1.a + w2 * q2Modified.a,
			w1 * q1.b + w2 * q2Modified.b,
			w1 * q1.c + w2 * q2Modified.c,
			w1 * q1.d + w2 * q2Modified.d
		);
	}

	// Convert quaternion to a rotation matrix (3x3)
	void toMatrix(float matrix[3][3]) const {
		matrix[0][0] = 1 - 2 * b * b - 2 * d * d;
		matrix[0][1] = 2 * b * c - 2 * d * a;
		matrix[0][2] = 2 * b * d + 2 * c * a;

		matrix[1][0] = 2 * b * c + 2 * d * a;
		matrix[1][1] = 1 - 2 * b * b - 2 * d * d;
		matrix[1][2] = 2 * c * d - 2 * b * a;

		matrix[2][0] = 2 * b * d - 2 * c * a;
		matrix[2][1] = 2 * c * d + 2 * b * a;
		matrix[2][2] = 1 - 2 * b * b - 2 * c * c;
	}

	// Helper function for normalization
	//Quaternion normalized() const {
	//	float mag = magnitude();
	//	return (mag > 0) ? Quaternion(w / mag, x / mag, y / mag, z / mag) : Quaternion(1, 0, 0, 0);
	//}
};

class Colour {
private:
	float r;
	float g;
	float b;
	//float a;
public:
	// Default constructor (black color with full opacity)
	Colour() : r(0.0f), g(0.0f), b(0.0f) {}

	// Constructor to initialize from float values (0.0f to 1.0f)
	Colour(float _r, float _g, float _b) : r(clamp(_r)), g(clamp(_g)), b(clamp(_b)) {}

	unsigned char getR() const { return static_cast<unsigned char>(clamp_255(r * 255.f)); }
	unsigned char getG() const { return static_cast<unsigned char>(clamp_255(g * 255.f)); }
	unsigned char getB() const { return static_cast<unsigned char>(clamp_255(b * 255.f)); }

	//// Constructor to initialize from unsigned char values (0 to 255)
	Colour(unsigned char _r, unsigned char _g, unsigned char _b)
		: r(_r / 255.0f), g(_g / 255.0f), b(_b / 255.0f) {}

	// Operator overloads
	Colour operator+(const Colour& colour) const {
		return Colour(r + colour.r, g + colour.g, b + colour.b);
	}

	Colour operator*(const Colour& other) const {
		return Colour(r * other.r, g * other.g, b * other.b);
	}

	Colour operator*(float scalar) const {
		return Colour(r * scalar, g * scalar, b * scalar);
	}

	Colour operator/(float scalar) const {
		if (scalar != 0) {
			return Colour(r / scalar, g / scalar, b / scalar);
		}
		else {
			throw std::runtime_error("Division by zero error in Colour class.");
		}
	}

	// Helper function to clamp the value between 0.0 and 1.0
	static float clamp(float value) {
		return max(0.0f, min(1.0f, value));
	}

	static float clamp_255(float value) {
		return max(0.0f, min(255.0f, value));
	}

	// Print color values for testing
	void print() const {
		std::cout << "Colour (r, g, b): (" << r << ", " << g << ", " << b << ")\n";
	}
};

class ShadingFrame {
public:
	Vec3 u, v, w; // Orthonormal basis vectors

	// Construct the basis using Gram-Schmidt from one given vector (w)
	// make sure n is unit vector???
	ShadingFrame(const Vec3& n) {
		w = n;// .normalize();
		// n / w != 1
		Vec3 arbitraryVec = (fabs(w.x) > 0.9f) ? Vec3(0, 1, 0) : Vec3(1, 0, 0);

		u = w.cross(arbitraryVec).normalize();
		v = w.cross(u).normalize();
	}

	// Forward transformation: Transform a vector from local to world space
	Vec3 toWorld(const Vec3& localVec) const {
		return u * localVec.x + v * localVec.y + w * localVec.z;
	}

	// Inverse transformation: Transform a vector from world to local space
	Vec3 toLocal(const Vec3& worldVec) const {
		return Vec3(worldVec.dot(u), worldVec.dot(v), worldVec.dot(w));
	}

	void printBasis() const {
		std::cout << "u: (" << u.x << ", " << u.y << ", " << u.z << ")\n";
		std::cout << "v: (" << v.x << ", " << v.y << ", " << v.z << ")\n";
		std::cout << "w: (" << w.x << ", " << w.y << ", " << w.z << ")\n";
	}
};


//template<typename t>
//t perspectiveCorrectInterpolateAttribute(t a0, t a1, t a2, float v0_w, float v1_w, float v2_w, float alpha, float beta, float gamma, float frag_w)
//{
//	t attrib[3];
//	attrib[0] = a0 * v0_w * alpha;
//	attrib[1] = a1 * v1_w * beta;
//	attrib[2] = a2 * v2_w * gamma;
//	return ((attrib[0] + attrib[1] + attrib[2]) / frag_w);
//}


class Triangle_ {
public:
	Vec2 v0, v1, v2;
	Vec2 e0, e1, e2;
	Vec3 n0, n1, n2;
	Colour colour_v0, colour_v1, colour_v2;
	float A; // area of the triangle (1/2 canceled)
	float c0, c1, c2;
	float w0_clip, w1_clip, w2_clip;
	float z0_clip, z1_clip, z2_clip;
	float alpha, beta, gamma;
	float alpha_correct, beta_correct, gamma_correct;

	Triangle_(Vec2 _v0, Vec2 _v1, Vec2 _v2, Vec3 _n0, Vec3 _n1, Vec3 _n2, float w0, float w1, float w2, float z0, float z1, float z2) : colour_v0(255.f, 0, 0), colour_v1(0, 255.f, 0), colour_v2(0, 0, 255.f),
		v0(_v0), v1(_v1), v2(_v2), n0(_n0), n1(_n1), n2(_n2), w0_clip(w0), w1_clip(w1), w2_clip(w2), z0_clip(z0), z1_clip(z1), z2_clip(z2) {
		e0 = v1 - v0;
		e1 = v2 - v1;
		e2 = v0 - v2;
		A = abs(cross(e0, e1));
	}
	void print() {
		std::cout << "v0 " << v0.x << " " << v0.y << " v1 " << v1.x << " " << v1.y << " v2 " << v2.x << " " << v2.y << std::endl;
	}
	//Backface culling
	bool isBackFace() {
		Vec2 edge1 = v1 - v0;
		Vec2 edge2 = v2 - v0;
		// Counterclockwise: Cull if cross < 0, else ?
		return cross_lefttop(edge1, edge2) > 0;
	}

	//Rasterize
	bool Edge(Vec2 p) {
		Vec2 q0 = p - v0;
		Vec2 q1 = p - v1;
		Vec2 q2 = p - v2;

		c0 = cross_lefttop(q0, e0);
		c1 = cross_lefttop(q1, e1);
		c2 = cross_lefttop(q2, e2);

		alpha = c1 / A;
		beta = c2 / A;
		gamma = c0 / A;

		const float EPSILON = 1e-5; // A small tolerance value

		if (alpha >= 0 && beta >= 0 && gamma >= 0 && abs(alpha + beta + gamma - 1.0f) <= EPSILON) {
			return true;
		}
		return false;
	}

	void computePerspectiveCorrectBarycentric() {
		float frag_w = alpha * w1_clip + beta * w2_clip + gamma * w0_clip;
		alpha_correct = (alpha * w1_clip) / frag_w;
		beta_correct = (beta * w2_clip) / frag_w;
		gamma_correct = (gamma * w0_clip) / frag_w;
	}

	Vec3 interpolateNormal() {
		return ((n0 * gamma_correct + n2 * beta_correct + n1 * alpha_correct).normalize());
	}

	Colour getColor() {
		return (colour_v0 * gamma_correct + colour_v2 * beta_correct + colour_v1 * alpha_correct);
	}

	float getInterpolatedZ() {
		//std::cout << "z0 " << z0_clip << " " << "z1 " << z1_clip << " " << "z2 " << z2_clip << std::endl;
		//std::cout << "z_inter " << z0_clip * gamma_correct + z2_clip * beta_correct + z1_clip * alpha_correct << std::endl;
		return (z0_clip * gamma_correct + z2_clip * beta_correct + z1_clip * alpha_correct);
	}
};
