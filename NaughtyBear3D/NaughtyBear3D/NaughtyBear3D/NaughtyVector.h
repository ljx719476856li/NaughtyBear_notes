#pragma once
#include <algorithm>
#include "BearMatrix.h"

class NaughtyVector
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	NaughtyVector() = default;
	NaughtyVector(float x1, float y1, float z1, float w1) :x(x1), y(y1), z(z1), w(w1) {}
	NaughtyVector(const NaughtyVector& vec):x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}
	NaughtyVector& operator = (const NaughtyVector & vec)
	{
		if (&vec == this)
			return *this;

		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
		return *this;
	}
public:
	//向量长度
	float Length()const;
	//归一化
	NaughtyVector Normalize();
	//点乘，描述两个向量的相似程度 |a||b|cosθ 
	float Dot(const NaughtyVector& v) const;
	//叉乘(叉乘得到的向量垂直于原来的两个向量)
	NaughtyVector Cross(const NaughtyVector& v) const;
	//== 运算重载
	bool operator == (const NaughtyVector& v) const;
	//与变换矩阵相乘
	NaughtyVector operator*(const BearMatrix& m) const;
	//与Vector分量相乘
	NaughtyVector operator*(const NaughtyVector& vec)const;
	//与标量相乘
	NaughtyVector operator*(float factor)const;
	//+运算符重载	
	NaughtyVector operator+(const NaughtyVector& vec);
	//-运算符重载
	NaughtyVector operator-(const NaughtyVector& vec);
	//负号
	NaughtyVector operator-()const;
};

class NFLOAT3
{
public:
	float x;
	float y;
	float z;

public:
	NFLOAT3() = default;
	NFLOAT3(float r, float b, float g) :x(r), y(b), z(g) {}
	NFLOAT3(const NFLOAT3& f3) :x(f3.x), y(f3.y), z(f3.z) {}
	NFLOAT3& operator = (const NFLOAT3& f3) {
		if (this != &f3)
		{
			x = f3.x;
			y = f3.y;
			z = f3.z;
		}
		return *this;
	}
};

class NFLOAT2
{
public:
	float u;
	float v;


public:
	NFLOAT2() = default;
	NFLOAT2(float r, float b) :u(r), v(b) {}
	NFLOAT2(const NFLOAT2& f2) :u(f2.u), v(f2.v) {}
	NFLOAT2& operator = (const NFLOAT2& f2) {
		if (this != &f2)
		{
			u = f2.u;
			v = f2.v;
		}
		return *this;
	}
};
