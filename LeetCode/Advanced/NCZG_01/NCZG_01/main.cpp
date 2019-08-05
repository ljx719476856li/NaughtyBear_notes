#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void MergeSolution(vector<int> arr);

private:
	void SortProcess(vector<int> arr, int left, int right);
	void Merge(vector<int> arr, int left, int mid, int right);
};

void Solution::MergeSolution(vector<int> arr)
{
	if (arr.size() < 2)
		return;

	SortProcess(arr, 0, arr.size() - 1);
}

void Solution::SortProcess(vector<int> arr, int left, int right)
{
	if (left >= right)
		return;


	int mid = left + ((right - left) >> 1);
	SortProcess(arr, left, mid);
	SortProcess(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}

void Solution::Merge(vector<int> arr, int left, int mid, int right)
{
	vector<int> help(right - left + 1);
	int idx = 0; //移动中间数组的help的idx
	int iLeft = left;
	int iRight = mid + 1;
	int res = 0;
	while (iLeft <= mid && iRight <= right)
	{
		//res += arr[iLeft] < arr[iRight] ? arr[iLeft] * (right - iRight + 1) : 0;
		help[idx++] = arr[iLeft] < arr[iRight] ? arr[iLeft++] : arr[iRight++];
	}

	//放进最后剩余的数到help中
	while (iLeft <= mid)
		help[idx++] = arr[iLeft++];
	while (iRight <= right)
		help[idx++] = arr[iRight++];
	
	for (int i = 0; i < help.size(); i++)
		arr[i] = help[i];

}

//int main()
//{
//	vector<int> vec = { 1, 3, 4, 2, 5 };
//	Solution sln;
//	sln.MergeSolution(vec);
//
//	return 0;
//}