#include "NaughtyVector.h"


//向量长度
float NaughtyVector::Length()const 
{ 
	float sq = x*x + y*y + z*z;
	return static_cast<float>(sqrt(sq));
}
//归一化
NaughtyVector NaughtyVector::Normalize() 
{ 
	float length = Length(); //获取到向量的长度，也就是模
	if (length != 0.0f)
	{
		float inv = 1.0f / length;
		x *= inv;
		y *= inv;
		z *= inv;
	}
}

//点乘，描述两个向量的相似程度 |a||b|cosθ 
float NaughtyVector::Dot(const NaughtyVector& v) const 
{
	return x * v.x + y * v.y + z * v.z;
}

//叉乘(叉乘得到的向量垂直于原来的两个向量)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const 
{
	float m1 = y * v.z - z * v.y;
	float m2 = z * v.x - x * v.z;
	float m3 = x * v.y - y * v.x;

	return NaughtyVector(m1, m2, m3, 0.0f);
}

//== 运算重载
bool NaughtyVector::operator == (const NaughtyVector& v) const { return true; }

//与变换矩阵相乘
NaughtyVector NaughtyVector::operator*(const BearMatrix& m) const { return NaughtyVector(1, 2, 3 ,4); }

//与Vector分量相乘
NaughtyVector NaughtyVector::operator*(const NaughtyVector& vec)const { return vec; }

//与标量相乘
NaughtyVector NaughtyVector::operator*(float factor)const { return NaughtyVector(1, 2, 3, 4); }

//+运算符重载
NaughtyVector NaughtyVector::operator+(const NaughtyVector& vec) { return vec; }

//-运算符重载
NaughtyVector NaughtyVector::operator-(const NaughtyVector& vec) { return vec; }

//负号
NaughtyVector NaughtyVector::operator-()const { return *this; }