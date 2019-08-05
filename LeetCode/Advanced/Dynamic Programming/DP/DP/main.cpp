#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int MaxSum(const vector<int> & vec, int idx);
	int MaxSumByDP(const vector<int> & vec, int idx);
private:

};

//int num1 = idx > 0 ? (vec[idx - 2] + vec[idx]) : vec[idx];
//int num2 = idx > 0 ? vec[idx - 1] : vec[idx];
//m_optValue[idx] = std::max(num1, num2);

//递归版本 时间复杂度根据规模可能达到 O(2^n)
int Solution::MaxSum(const vector<int> & vec, int idx)
{
	//递归出口
	if (idx == 0)
		return vec[idx];
	else if (idx == 1)
	{
		return max(vec[0], vec[idx]);
	}

	return max(MaxSum(vec, idx - 1), MaxSum(vec, idx - 2) + vec[idx]);
}

//DP方法
int Solution::MaxSumByDP(const vector<int> & vec, int idx)
{
	vector<int> m_optValue(vec.size(), -1);

	m_optValue[0] = vec[0];
	m_optValue[1] = max(vec[0], vec[1]);

	for (int i = 2; i < vec.size(); i++)
		m_optValue[i] = max(m_optValue[i - 1], m_optValue[i - 2] + vec[i]);

	return m_optValue[idx];
}

int main()
{
	//求出一下数组不相邻数的和的最大值
	//vector<int> vec = {4, 1, 1, 9, 1};
	vector<int> vec = { 1, 2, 4, 1, 7, 8, 3 };
	Solution sln;
	int max = sln.MaxSumByDP(vec, vec.size() - 1);
	
	return 0;
}