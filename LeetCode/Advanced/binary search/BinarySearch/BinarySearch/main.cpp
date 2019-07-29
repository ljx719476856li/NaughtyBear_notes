#include "Solution.h"
#include "TimeMap.h"

void main()
{
	TimeMap kv;
	kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
	cout << kv.get("foo", 1) << " ";  // 输出 "bar"   
	cout << kv.get("foo", 3) << " "; // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
	kv.set("foo", "bar2", 4);
	cout << kv.get("foo", 4) << " "; // 输出 "bar2"   
	cout << kv.get("foo", 5) << " "; // 输出 "bar2" 


	//Solution sln;
	//vector<int> vec = { };
	//vector<int> res;

	//int idx = sln.searchInsert(vec, 5);
	//res = sln.searchRange(vec, 0);
	
	return;
}