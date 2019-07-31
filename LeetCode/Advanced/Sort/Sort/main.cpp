#pragma once
#include "BubbleSort.hpp"

int main()
{
	Bubble bubble;
	std::vector<std::string> vec({"aaa", "bbb", "ccc"});

	bubble.BubbleSort1<std::string>(vec, vec.size());
	//bubble.BubbleSort(vec);

	return -1;
}
