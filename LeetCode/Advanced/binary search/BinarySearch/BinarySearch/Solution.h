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
};