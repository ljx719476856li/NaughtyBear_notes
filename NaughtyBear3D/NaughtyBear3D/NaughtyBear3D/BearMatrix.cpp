#include "BearMatrix.h"

//置为单位矩阵
void BearMatrix::Identity()
{
	_11 = 1.0f; _12 = 0.0f; _13 = 0.0f; _14 = 0.0f;
	_21 = 0.0f; _22 = 1.0f; _23 = 0.0f; _24 = 0.0f;
	_31 = 0.0f; _32 = 0.0f; _33 = 1.0f; _34 = 0.0f;
	_41 = 0.0f; _42 = 0.0f; _43 = 0.0f; _44 = 1.0f;
}

//0矩阵
void BearMatrix::SetZero()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].assign({ 0, 0, 0, 0 });
	}
}

//等于重载
bool	BearMatrix::operator ==(const BearMatrix& m) const 
{
	if (m.matrix == this->matrix)
		return true;

	return false; 
}

//+ 运算符重载
BearMatrix&& BearMatrix::operator+(const BearMatrix& m) const 
{ 
	BearMatrix mat;
	for (int  i = 0; i < m.matrix.size(); i++)
	{
		for (int  j = 0; j < m.matrix.size(); j++)
		{
			mat.matrix[i][j] = m.matrix[i][j] + matrix[i][j];
		}
	}

	return std::move(mat);
}

//- 运算符重载
BearMatrix BearMatrix::operator - (const BearMatrix& m) const 
{ 
	BearMatrix mat;
	for (int i = 0; i < m.matrix.size(); i++)
	{
		for (int j = 0; j < m.matrix.size(); j++)
		{
			mat.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}

	return mat;
}

//m1 = m2 * m3
BearMatrix BearMatrix::operator * (const BearMatrix& m) const 
{
	BearMatrix mat;
	for (int i = 0; i < m.matrix.size(); i++)
	{
		for (int j = 0; j < m.matrix.size(); j++)
		{
			mat.matrix[j][i] = (matrix[j][0] * m.matrix[0][i]) +
				(matrix[j][1] * m.matrix[1][i]) +
				(matrix[j][2] * m.matrix[2][i]) +
				(matrix[j][3] * m.matrix[3][i]);
		}
	}

	return mat;
}