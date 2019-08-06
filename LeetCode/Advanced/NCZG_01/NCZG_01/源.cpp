#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int len;
	int MergeSolution(int arr[]);

private:

	int SortProcess(int arr[], int left, int right);
	int Merge(int arr[], int left, int mid, int right);
};

int Solution::MergeSolution(int arr[])
{
	if (arr == nullptr && len < 2)
		return -1;

	return SortProcess(arr, 0, len - 1);
}

int Solution::SortProcess(int arr[], int left, int right)
{
	if (left >= right)
		return 0;


	int mid = left + ((right - left) >> 1);
	return SortProcess(arr, left, mid) + SortProcess(arr, mid + 1, right) + Merge(arr, left, mid, right);
}

int Solution::Merge(int arr[], int left, int mid, int right)
{
	int len = right - left + 1;
	int* help = new int[len];
	int idx = 0; //移动中间数组的help的idx
	int iLeft = left;
	int iRight = mid + 1;
	int res = 0;
	while (iLeft <= mid && iRight <= right)
	{
		res += arr[iLeft] < arr[iRight] ? arr[iLeft] * (right - iRight + 1) : 0;
		help[idx++] = arr[iLeft] < arr[iRight] ? arr[iLeft++] : arr[iRight++];
	}

	//放进最后剩余的数到help中
	while (iLeft <= mid)
		help[idx++] = arr[iLeft++];
	while (iRight <= right)
		help[idx++] = arr[iRight++];

	for (int i = 0; i < len; i++)
		arr[left + i] = help[i];

	return res;
}

int main()
{
	/*vector<int> vec = { 1, 3, 4, 2, 5 };*/
	int arr[] = { 1, 3, 4, 2, 5 };
	int len = sizeof(arr) / sizeof(int);

	Solution sln;
	sln.len = len;
	int res = sln.MergeSolution(arr);

	return 0;
}