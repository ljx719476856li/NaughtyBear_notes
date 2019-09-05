#include "BearMatrix.h"

//单位化
void BearMatrix::Identity(){}

//0矩阵
void BearMatrix::SetZero(){}

//等于重载
bool	BearMatrix::operator ==(const BearMatrix& m) const{}

//+ 运算符重载
BearMatrix BearMatrix::operator+(const BearMatrix& m) const{}

//- 运算符重载
BearMatrix BearMatrix::operator - (const BearMatrix& m) const{}

//* 运算符重载
BearMatrix BearMatrix::operator * (const BearMatrix& m) const{}