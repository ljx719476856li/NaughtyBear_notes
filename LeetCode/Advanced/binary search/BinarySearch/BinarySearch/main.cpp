#include "Solution.h"

void main()
{
	Solution sln;
	vector<int> vec = { };
	vector<int> res;

	int idx = sln.searchInsert(vec, 5);
	res = sln.searchRange(vec, 0);
	
	return;
}