#include "NaughtyVector.h"

//向量长度
float NaughtyVector::Length()const { return 0; }

//归一化
NaughtyVector NaughtyVector::Normalize() { return NaughtyVector(1, 2, 3, 4); }

//点乘，描述两个向量的相似程度 |a||b|cosθ 
float NaughtyVector::Dot(const NaughtyVector& v) const { return y; }

//叉乘(叉乘得到的向量垂直于原来的两个向量)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const { return v; }

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