#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目：给定两个数组w和v，两个数组长度相等，w[i]表示第i件商品的重量，v[i]表示第i件商品的价值。
		再给定一个整数bag，要求你挑选商品的重量加起来一定不能超过bag，返回满足这个条件下，你能获得的最大价值。
思路：
		(1) 先做出递归版本
			i). 扣定边界及出口
				a). 挑选商品的重量加起来一定不能超过bag
			ii). 普通情况，则是选和不选两种情况
				a). 选择，
				b). 不选择
		(2) 将递归版本改进为动态规划版本
			i). 分析可变参数(解空间)
				a). 二维表
				b). 可变参数，i和alreadyWeight
			ii). 确定最终状态
				a). (0, 0)
			iii). 根据base case确定初始
				a). 当i == values.size()时，返回0
			IV). 分析普通位置依赖性
				a). i依赖i+1
				b). alreadyWeight依赖alreadyWeight + weights[i]
*/

class Knapsack
{
public:
	int maxValue(vector<int> values, vector<int> weights, int bag);

	//递归版本
	//参数：values: 价值数组， weights：重量数组
	//bag：背包总重量， alreadyWeight： 已挑选总重量
	//返回值：最大价值
	int Process(vector<int> values, vector<int> weights, int bag, int i, int alreadyWeight);

	int DP(vector<int> values, vector<int> weights, int bag);
};

int Knapsack::DP(vector<int> values, vector<int> weights, int bag)
{
	vector<vector<int>> dp(values.size() + 1, vector<int>(weights.size() + 1, 0));

	for (int i = values.size() - 1; i >= 0; i--)
	{
		for (int j = bag; j >= 0; j--)
		{
			dp[i][j] = dp[i + 1][j];
			if (j + weights[i] < bag)
				dp[i][j] = max(dp[i][j], values[i] + dp[i + 1][j + weights[i]]);
		}
	}

	return dp[0][0];
}


int Knapsack::maxValue(vector<int> values, vector<int> weights, int bag)
{
	return Process(values, weights, bag, 0, 0);
}

int Knapsack::Process(vector<int> values, vector<int> weights, int bag, int i, int alreadyWeight)
{
	//超过bag的重量直接返回系统最小值
	if (alreadyWeight > bag)
		return INT_MIN;

	//等于bag的部分，直接返回0，由递归方程累加上结尾前的部分
	if (i == weights.size())
		return 0;

	return max(
		Process(values, weights, bag, i + 1, alreadyWeight),
		values[i] + Process(values, weights, bag, i + 1, alreadyWeight + weights[i])
	);
}

int main()
{
	vector<int> values = { 3, 2, 4, 7 };
	vector<int> weights= { 5, 6, 3, 19 };
	int bag = 11;

	Knapsack sln;
	cout << sln.maxValue(values, weights, bag);
	cout << sln.DP(values, weights, bag);

	return 0;
}