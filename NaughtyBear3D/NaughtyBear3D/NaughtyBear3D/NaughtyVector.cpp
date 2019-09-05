#include "NaughtyVector.h"

//向量长度
float NaughtyVector::Length()const {}

//归一化
NaughtyVector NaughtyVector::Normalize(){}

//点乘，描述两个向量的相似程度 |a||b|cosθ 
float NaughtyVector::Dot(const NaughtyVector& v) const{}

//叉乘(叉乘得到的向量垂直于原来的两个向量)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const{}

//== 运算重载
bool NaughtyVector::operator == (const NaughtyVector& v) const{}

//与变换矩阵相乘
NaughtyVector NaughtyVector::operator*(const BearMatrix& m) const{}

//与Vector分量相乘
NaughtyVector NaughtyVector::operator*(const NaughtyVector& vec)const{}

//与标量相乘
NaughtyVector NaughtyVector::operator*(float factor)const{}

//+运算符重载
NaughtyVector NaughtyVector::operator+(const NaughtyVector& vec){}

//-运算符重载
NaughtyVector NaughtyVector::operator-(const NaughtyVector& vec){}

//负号
NaughtyVector NaughtyVector::operator-()const{}