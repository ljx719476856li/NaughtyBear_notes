#include "BearMatrix.h"


int main()
{
	BearMatrix matrix;

	vector<vector<float>> m{ {1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4} };
	matrix = m;

	BearMatrix mat = matrix * matrix;

	matrix.SetZero();
	return 0;
}