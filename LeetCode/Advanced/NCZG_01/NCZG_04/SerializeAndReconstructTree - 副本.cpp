#include<bits/stdc++.h>
using namespace std;

/*
题目：给一串数字分组，分组条件如下：
1. 三张牌为连续自然数
2. 三张牌相同
思路：
先对字符串排序，排序完成之后，通过遍历数字判断以上两个条件
*/

class Solution
{
public:
	int Process(int* nums, int len);
	bool isLianXu(int* nums, int len);

};

bool Solution::isLianXu(int* nums, int len)
{
	if (len < 3)
		return true;

	bool test = isLianXu(++nums, 3);
	if ((nums[0] + nums[len - 1] - len) == 1)
		return true;
}


int Solution::Process(int* nums, int len)
{
	if (len <= 0)
		return 0; //0分组

	sort(nums, nums + len); //升序排序
	int ans = unique(nums, nums + len) - nums;
	int res = 0;
	bool IsLianXu = false;
	int mid = ans / 2;
	isLianXu(nums, len);


	int count = 0;
	int temp = 0;
	//判断是否相同
	for (int i = 1; i < len; i++)
	{
		temp = nums[i - 1];
		//不想同
		if (temp - nums[i] < 0)
		{
			count = 0;
			continue;
		}
		if ((++count) == 2)
			res++;
	}
	return res;
}

/*12 6
1, 5, 3, 3, 3, 4, 3, 5, 3, 2, 3, 3 */
int main()
{
	int vec[] = { 1, 5, 3, 3, 3, 4, 3, 5, 3, 2, 3, 3 };
	Solution sln;


	int res = sln.Process(vec, sizeof(vec) / sizeof(int));


	return 0;
}