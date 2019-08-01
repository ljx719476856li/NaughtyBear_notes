#pragma once
#include <iostream>
#include <vector>
/*
（小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
快速排序思路：
1. 选取第一个数为基准
2. 将比基准小的数交换到前面，比基准大的数交换到后面
3. 对左右区间重复第二步，直到各区间只有一个数
*/

// ----------------------------------------------------
class Quick
{
public:
	// 快速排序（递归）
	void QuickSort(std::vector<int>& v, int low, int high);
	void quick_sort(std::vector<int>& vec, int left, int right);
	template<typename T>
	void QuickSort2(std::vector<T>& vec, int low, int high);
private:
	//找基准数 划分
	int partition(std::vector<int>& vec, int left, int right);
};


int Quick::partition(std::vector<int>& vec, int left, int right)  //找基准数 划分
{
	int i = left + 1;
	int j = right;
	int temp = vec[left];

	while (i <= j)
	{
		while (vec[i] < temp)
		{
			i++;
		}
		while (vec[j] > temp)
		{
			j--;
		}
		if (i < j)
			std::swap(vec[i++], vec[j--]);
	}
	std::swap(vec[j], vec[left]);
	return j;

}

void Quick::quick_sort(std::vector<int>& vec, int left, int right)
{
	if (left > right)
		return;
	int j = partition(vec, left, right);
	quick_sort(vec, left, j - 1);
	quick_sort(vec, j + 1, right);
}


// 快速排序（递归）
void Quick::QuickSort(std::vector<int>& vec, int low, int high)
{
	if (low >= high)
		return;

	int first = low, last = high, key = vec[first];
	while (first < last)
	{
		//将小于第一个的元素移到开头（左边）
		while (first < last && vec[last] >= key)
			last--;
		if (first < last)
			vec[first++] = vec[last];

		//将大于第一个的元素移到结尾（右边）
		while (first < last && vec[first] <= key)
			first++;
		if (first < last)
			vec[last--] = vec[first];
	}

	vec[first] = key;

	//左区间
	QuickSort(vec, low, first - 1);
	//右区间
	QuickSort(vec, first + 1, high);
}

//模板实现
template<typename T>
void Quick::QuickSort2(std::vector<T>& vec, int low, int high)
{
	if (low >= high)
		return; //结束位

	int first = low, last = high, key = vec[first];
	while (first < last)
	{
		//将小于第一个的元素移动到开头处(左边)
		while (first < last && vec[last] >= key)
			last--;
		if (first < last)
			vec[first++] = vec[last];


		//将大于第一个的元素移动到结尾处(右边)
		while (first < last && vec[first] <= key)
			first++;
		if (first < last)
			vec[last--] = vec[first];
	}

	vec[first] = key; 

	QuickSort2(vec, low, first - 1);
	QuickSort2(vec, first + 1, high);
}