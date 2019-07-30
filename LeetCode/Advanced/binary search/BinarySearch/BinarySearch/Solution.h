#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//�����������в���Ԫ�صĵ�һ�������һ��λ��
	//����һ�������������е��������� nums����һ��Ŀ��ֵ target��
	//�ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
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

	//704.���ֲ���
	//����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target
	//дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1
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
		//targetֵ����nums����Ԫ�أ���������
		if (nums.back() < target) return nums.size();
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2; //��ֹԽ�� 
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return right;
	}
};