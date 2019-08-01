#include "HeapSort.hpp"

void main()
{
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8 /*6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6*/ };
	int len = (int) sizeof(arr) / sizeof(*arr);
	
	HeapSort hs;
	hs.heap_sort(arr, len);
	//for (int i = 0; i < len; i++)
		//cout << arr[i] << ' ';
	//std::cout << endl;

	return;
}