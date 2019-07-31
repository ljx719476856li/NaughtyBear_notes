#pragma once
#include <iostream>
#include <vector>

class Bubble
{
public:

	//冒泡排序
	void BubbleSort(std::vector<int>& v);

	// 模板实现冒泡排序
	template<typename T> 	//整数或者浮点数皆可使用，若要使用物体(class)时必须设定大于(＞)的运算功能
	void BubbleSort1(std::vector<T>& arr, int len);


	// 冒泡排序（改进版）
	void BubbleSort2(std::vector<int>& v);
};



/*
（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。
选择排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/


//冒泡排序
void Bubble::BubbleSort(std::vector<int>& vec)
{
	int len = vec.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (vec[i] < vec[j])
				std::swap(vec[i], vec[j]);
		}
	}
	return;
}

// 模板实现冒泡排序
template<typename T>
void Bubble::BubbleSort1(std::vector<T>& arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] < arr[j])
				std::swap(arr[i], arr[j]); 
		}
	}
	return;
}

//
//// 冒泡排序（改进版）
//void Bubble::BubbleSort2(std::vector<int>& vec)
//{}
