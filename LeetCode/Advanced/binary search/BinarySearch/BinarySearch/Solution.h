#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		//target值大于nums所有元素，则加在最后
		if (nums.back() < target) return nums.size();
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2; //防止越界 
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return right;
	}

	//在排序数组中查找元素的第一个和最后一个位置
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res(2, -1);
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		if (nums[right] != target) return res;
		res[0] = right;
		right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= target) left = mid + 1;
			else right = mid;
		}
		res[1] = left - 1;
		return res;
	}
};