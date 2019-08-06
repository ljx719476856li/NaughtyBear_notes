#include <iostream>
#include <vector>
#include <algorithm>
#include <Random>
using namespace std;


class Solution
{
public:
	void QuickSort(vector<int>& vec);

private:
	void QuickSort(vector<int>& vec, int left, int right);
	vector<int> Partition(vector<int>& vec, int left, int right);

};
void Solution::QuickSort(vector<int>&  vec)
{
	if (vec.size() < 2)
		return;

	QuickSort(vec, 0, vec.size() - 1);
}

void Solution::QuickSort(vector<int>&  vec, int left, int right)
{
	if (left < right)
	{
		swap(vec[left + (int)(rand() % (right - left + 1))], vec[right]);
		vector<int> range = Partition(vec, left, right);
		QuickSort(vec, left, range[0] - 1);
		QuickSort(vec, range[1] + 1, right);
	}

}

vector<int> Solution::Partition(vector<int>&  vec, int left, int right)
{
	int less = left - 1;
	int more = right;
	int idx = left;
	while (idx < more)
	{
		if (vec[idx] < vec[right])
			swap(vec[++less], vec[idx++]);
		else if (vec[idx] > vec[right])
			swap(vec[--more], vec[idx]);
		else
			idx++;
	}

	swap(vec[more], vec[right]);
	return { less + 1, more };
}

int main()
{
	vector<int> vec = { 6, 5, 10, 3, 2, 1 };

	Solution sln;
	sln.QuickSort(vec);

	return -1;
}