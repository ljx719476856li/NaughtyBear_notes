#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int MaxSum(const vector<int> & vec, int idx);

private:
	vector<int> m_optValue;
};

//int num1 = idx > 0 ? (vec[idx - 2] + vec[idx]) : vec[idx];
//int num2 = idx > 0 ? vec[idx - 1] : vec[idx];
//m_optValue[idx] = std::max(num1, num2);

int Solution::MaxSum(const vector<int> & vec, int idx)
{
	if (idx == 0)
		return vec[idx];

	return 0;
}


int main()
{


	return 0;
}