#include <iostream>
#include <vector>
using namespace std;

/*
题目：给你一个数组arr，和一个整数aim。如果可以任意选择arr中的数字，能不能累加到aim，返回true或者false
思路：arr: [3, 2, 7], aim:10
			(1) 展开arr的结果，选或不选
			(2) 设置idx, sum
				i). idx: 当前节点位置
				ii). sum: 当前节点位置之前被选择数的和
			(3) 边界扣定
				i). 当idx == arr.length，到达结尾
				ii). 当sum == aim，返回true
					a). 选择情况 || 不选择情况，或的关系
*/

class MoneyProblem
{
public:
	//递归版本
	//参数：idx：当前节点位置，sum：当前节点位置之前被选择数的和
	//返回值：true表示能累加到aim，反之false
	bool Process(vector<int> nums, int sum, int idx, int aim);

	bool DP(vector<int> nums, int aim);
};

bool MoneyProblem::DP(vector<int> nums, int aim)
{
	vector<vector<bool>> dp(nums.size() + 1, vector<bool>(aim + 1, false)); //大小赋值
	
	for (int i = 0; i < dp.size(); i++)
		dp[i][aim] = true;
	
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		for (int j = aim - 1; j >= 0; j --)
		{
			dp[i][j] = dp[i + 1][j];
			if (j + nums[i] <= aim)
				dp[i][j] = dp[i][j] || dp[i + 1][j + nums[i]];
		}
	}

	return dp[0][0];
}

bool MoneyProblem::Process(vector<int> nums, int sum, int idx, int aim)
{
	if (nums.size() == idx)
		return aim == sum;
	

	return (Process(nums, sum, idx + 1, aim)
				||
		Process(nums, sum + nums[idx], idx + 1, aim)
		);
}

//int main()
//{
//	vector<int> nums = { 3, 2, 7 };
//	MoneyProblem sln;
//	bool flag = sln.DP(nums, 10);
//	flag = sln.Process(nums, 0, 0, 10);
//	return 0;
//}