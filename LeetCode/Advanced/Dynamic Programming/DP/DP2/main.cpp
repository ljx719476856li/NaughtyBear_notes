#include <iostream>
#include <vector>
#include <map>
using namespace std;

//https://www.youtube.com/watch?v=Jakbj4vaIbE&t=682s 题目
class Solution
{
public:
	bool SubSet(const vector<int>& vec, int len,int num);
	bool SubSetByDP(const vector<int>& vec, int len,int num);
};

//递归版本
bool Solution::SubSet(const vector<int>& vec, int idx, int num) 
{
	//递归出口
	if (num == 0)
		return true;
	else if (idx == 0)
		return vec[idx] == num;
	else if (vec[idx] > num) //因为vec当下节点的数大于num，则不能选择次元素
		return SubSet(vec, idx - 1, num);
	
	return ((SubSet(vec, idx - 1, num - vec[idx])) || (SubSet(vec, idx - 1, num)));
}

bool Solution::SubSetByDP(const vector<int>& vec, int idx, int num)
{
	vector<vector<bool>> subOpt(vec.size(), vector<bool>(num + 1));
	for (int i = 0; i < num + 1; i++)
		subOpt[0][i] = false;
	for (int i = 0; i < vec.size(); i++)
		subOpt[i][0] = true;

	subOpt[0][vec[0]] = true;

	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = 1; j < num + 1; j++)
		{
			if (vec[i] > j)
				subOpt[i][j] = subOpt[i - 1][j];
			else
				subOpt[i][j] = subOpt[i - 1][j - vec[i]] || subOpt[i - 1][j];
		}
	}

	return subOpt[idx][num];
}

int main()
{
	vector<int> vec = { 3, 34, 4, 12, 5, 2 };

	Solution sln;
	//bool flag1 = sln.SubSetByDP(vec, vec.size() - 1, 9);
	//bool flag2 = sln.SubSetByDP(vec, vec.size() - 1, 10);
	//bool flag3 = sln.SubSetByDP(vec, vec.size() - 1, 11);
	//bool flag4 = sln.SubSetByDP(vec, vec.size() - 1, 12);
	bool flag5 = sln.SubSetByDP(vec, vec.size() - 1, 13);

	return 0;
}