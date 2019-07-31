#include "SelectionSort.hpp"

int main()
{
	std::vector<int32_t> vec({6, 10, 2, 1, 8, 0});

	Selection sel;
	//sel.SelectionSort(vec);
	sel.Selection_Sort<int32_t>(vec);
	return -1;
}