#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/*
求相邻俩数的最大值，，要求时间复杂度O(N)，且要求不能用基于比较的排序
思路：使用类似桶排序的思想，对于N个数，用N+1个桶作为容器，然后把最小值放在开头，最大值放在结尾，
由此可得中间必有空桶，有此可证出桶内的相邻数必定小于非相桶内的相邻数
然后依次按照桶给定的范围放入元素，最后差值比较
*/
class Solution
{
public:
	int maxGap(vector<int> vec);
private:
	int bucket(int num, int min, int max, int len);
};

int Solution::maxGap(vector<int> vec)
{
	if (vec.size() < 2)
		return -1;
	int len = vec.size();
	int mins = INT_MAX;
	int maxs = INT_MIN;
	for (int i = 0; i < len; i++)
	{
		mins = min(mins, vec[i]);
		maxs = max(maxs, vec[i]);
	}
	if (mins == maxs)
	{
		return 0; //数组元素都相同
	}

	vector<bool> hasNum(len + 1);
	vector<int> maxsNum(len + 1);
	vector<int> minsNum(len + 1);
	for (int i = 0; i < len ; i++)
	{
		int bid = bucket(vec[i], mins, maxs, len);
		maxsNum[bid] = hasNum[bid] ? max(maxsNum[bid], vec[i]) : vec[i];
		minsNum[bid] = hasNum[bid] ? min(minsNum[bid], vec[i]) : vec[i];
		hasNum[bid] = true;
	}
	int res = 0;
	int beforeMax = maxsNum[0];
	for (int i = 1; i <= len; i++)
	{
		if (hasNum[i])
		{
			int nextMin = minsNum[i];
			res = max(res, nextMin - beforeMax);
			beforeMax = maxsNum[i];
		}
	}

	return res;
}

int Solution::bucket(int num, int min, int max, int len)
{
	return ((num - min) * len / (max - min));
}

int main()
{
	vector<int> vec = { 9, 0, 8, 3, 13, 6, 1, 5, 2, 7, 4 };
	Solution sln;
	int res = sln.maxGap(vec);
	return -1;
}