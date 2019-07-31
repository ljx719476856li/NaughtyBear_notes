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
	void BubbleSort1(T arr[], int len);


	// 冒泡排序（改进版）
	void BubbleSort2(std::vector<int>& v);
};

