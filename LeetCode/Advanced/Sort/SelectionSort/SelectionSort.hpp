#pragma once
#include <iostream>
#include <vector>
/*
（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。
选择排序思路：
1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕
4. 从第一个位置开始比较，找出最小的，和第一个位置互换，开始下一轮。
*/
class Selection
{
public:
	// 选择排序
	void SelectionSort(std::vector<int>& v);

	// 模板实现
	template<typename T>
	void Selection_Sort(std::vector<T>& arr);
};

template<typename T>
void Selection::Selection_Sort(std::vector<T>& arr) 
{
	int min, len = arr.size();
	for (int i = 0; i < len - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (i != min)
			std::swap(arr[i], arr[min]);
	}
	return;
}

void Selection::SelectionSort(std::vector<int>& vec)
{
	int min, len = vec.size() - 1;
	for (int i = 0; i < len; i ++)
	{
		min = i;
		for (int j = i + 1; j <= len; j++)
		{
			if (vec[min] > vec[j])
				min = j;
		}
		if (i != min)
			std::swap(vec[i], vec[min]);
	}

	return;
}