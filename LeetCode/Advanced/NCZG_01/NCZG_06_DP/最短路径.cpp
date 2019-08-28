#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
题目：给你给二维数组，二位数组中的每个数都是正数，要求从左上角走到右下角，每一步只能向右或者向下。沿途经过的数字要累加起来。返回最小的路径和
思路：
		(1) 递归思想处理，横坐标是x，纵坐标y
		(2) 递归出口，边界情况
			i) 已经到达右下角，直接返回右下角值
			ii) x，y都到达边界
				a) x == matrix.length - 1 时，x不能再增大，及此时只能右移
				b) y == matrix[0].length - 1时，y不能再增大，及此时只能下移
		(3) 对于普通情况，求得min(↓， →)

*/
class MinPath
{
public:
	//递归处理
	//参数：matrix: 矩阵， x: 行， y: 列
	//返回最小路径
	int Process(vector<vector<int>> matrix, int x, int y); 

	//记忆搜索法
	int MemoryProcess(vector<vector<int>> matrix, int x, int y);
	unordered_map<string, int> m_haspMap;

	//DP
	int DPProcess(vector<vector<int>> matrix);
};



//记忆搜索法
int MinPath::MemoryProcess(vector<vector<int>> matrix, int x, int y)
{
	//递归出口 && 边界扣定
	if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
		return matrix[x][y]; //直接返回右下角值
	if (x == matrix.size() - 1)  //x已经到达边界不能再增大，及此时只能右移
	{
		string key = to_string(x) + '-' + to_string(y + 1);
		if (m_haspMap.find(key) == m_haspMap.end())
			m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, x, y + 1);

		return m_haspMap[key];
	}//return matrix[matrix.size() - 1][++y]; //向右移动
	if (y == matrix[0].size() - 1) //x已经到达边界不能再增大，及此时只能右移
	{
		string key = to_string(x + 1) + '-' + to_string(y);
		if (m_haspMap.find(key) == m_haspMap.end())
			m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, x + 1, y);

		return m_haspMap[key];
		//return matrix[++x][matrix[0].size() - 1]; //向下移动
	}
	int row = x, column = y;
	row += matrix[x + 1][y] == min(matrix[x + 1][y], matrix[x][y + 1]) ? 1 : 0;
	column += x == row ? 1 : 0;
	
	string key = to_string(x) + '-' + to_string(y);
	m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, row, column);

	return m_haspMap[key];
}

//DP
int MinPath::DPProcess(vector<vector<int>> matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col));

	dp[0][0] = matrix[0][0];
	for (int i = 1; i < row; i++)
		dp[i][0] = dp[i - 1][0] + matrix[i][0];
	for (int j = 1; j < col; j++)
		dp[0][j] = dp[0][j - 1] + matrix[0][j];
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
	}
	return dp[row - 1][col - 1];
}

//递归处理
//参数：matrix: 矩阵， x: 行， y: 列
//返回最小路径
int MinPath::Process(vector<vector<int>> matrix, int x, int y)
{
	//递归出口 && 边界扣定
	if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
		return matrix[x][y]; //直接返回右下角值
	if (x == matrix.size() - 1)  //x已经到达边界不能再增大，及此时只能右移
		return matrix[x][y] + Process(matrix, x, y + 1);
	//return matrix[matrix.size() - 1][++y]; //向右移动
	if (y == matrix[0].size() - 1) //x已经到达边界不能再增大，及此时只能右移
		return matrix[x][y] + Process(matrix, x + 1, y);
	//return matrix[++x][matrix[0].size() - 1]; //向下移动

	int row = x, column = y;
	row += matrix[x + 1][y] == min(matrix[x + 1][y], matrix[x][y + 1]) ? 1 : 0;
	column += x == row ? 1 : 0;

	return matrix[x][y] + Process(matrix, row, column);

}

/*
int main()
{
	vector<vector<int>> matrix = { {3, 2, 1, 0}, {7, 5, 0, 1}, {3, 7, 6, 2} };

	MinPath sln;
	//int res = sln.Process(matrix, 0, 0);
	//int res = sln.MemoryProcess(matrix, 0, 0);
	int res = sln.DPProcess(matrix);
	return 0;
}
*/

