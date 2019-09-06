#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class BearMatrix
{
public:
	union
	{
		vector<vector<float>> matrix;
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
	};

public:
	BearMatrix() 
	{ 
		matrix.resize(4, {0, 0, 0, 0});
		std::cout << "构造函数" << std::endl;
	}
	BearMatrix(float a1, float a2, float a3, float a4,
		float b1, float b2, float b3, float b4,
		float c1, float c2, float c3, float c4,
		float d1, float d2, float d3, float d4)
	{
		_11 = a1, _12 = a2, _13 = a3, _14 = a4;
		_21 = b1; _22 = b2; _23 = b3; _24 = b4;
		_31 = c1; _32 = c2; _33 = c3; _34 = c4;
		_41 = d1, _42 = d2, _43 = 43, _44 = d4;
	}
	BearMatrix(const BearMatrix& m)
	{
		matrix = m.matrix;
	}
	BearMatrix& operator = (const BearMatrix& m)
	{
		if (matrix != m.matrix)
			matrix = m.matrix;
		return *this;
	}	
	BearMatrix& operator = (const vector<vector<float>>& m)
	{
		if (matrix != m)
			matrix = m;
		return *this;
	}
	~BearMatrix() { std::cout << "析构函数" << std::endl; }
public:
	//单位化
	void Identity();
	//0矩阵
	void SetZero();
	//等于重载
	bool	operator ==(const BearMatrix& m) const;
	//+ 运算符重载
	BearMatrix&& operator+(const BearMatrix& m) const;
	//- 运算符重载
	BearMatrix operator - (const BearMatrix& m) const;
	//* 运算符重载
	BearMatrix operator * (const BearMatrix& m) const;
};

