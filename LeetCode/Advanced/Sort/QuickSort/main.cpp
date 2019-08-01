#include "QuickSort.hpp"
#include <time.h>


void main()
{
	const int NUM = 10;
	std::vector<int> vec(NUM, -1);
	std::vector<float> vec2({3, 5, 1, 6 ,0, 12, 7, 2, 4});
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < NUM; i++)
	{
		vec[i] = rand() % 100 + 1;
	}

	Quick qk;
	qk.QuickSort2(vec2, 0, vec2.size() - 1);

	return;
}