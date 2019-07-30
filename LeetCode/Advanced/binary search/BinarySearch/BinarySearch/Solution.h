#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//在排序数组中查找元素的第一个和最后一个位置
	//给定一个按照升序排列的整数数组 nums，和一个目标值 target。
	//找出给定目标值在数组中的开始位置和结束位置。
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> res(2, -1);
		int left = 0, right = nums.size() - 1;
		if (right < 0)
			return res;



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

	//704.二分查找
	//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target
	//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
	int search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return -1;
	}

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

	bool search2(vector<int>& nums, int target)
	{
		int n = nums.size(), left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] >= target) left = mid + 1;
				else right = mid - 1;
			}
			else if (nums[mid] > nums[right]) {
				if (nums[left] <= target && nums[mid] > target) right = mid - 1;
				else left = mid + 1;
			}
			else --right;
		}
		return false;
	}
};