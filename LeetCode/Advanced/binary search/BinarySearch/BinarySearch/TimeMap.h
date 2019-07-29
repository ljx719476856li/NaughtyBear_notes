#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <numeric>
#include <map>

using namespace std;

//vector<tuple<string, string, int> > vec;
//auto iter = back_inserter(vec);
//vector<pair<string, map<string, int> > > vec;
//auto iter = back_inserter(vec);
//multimap<string, map<string, int> > mun;

class TimeMap {
public:
	TimeMap() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	}

	void set(string key, string value, int timestamp) {
		mun[key].insert(map<int, string>::value_type(timestamp, value));//存储set()函数的参数值
	}

	string get(string key, int timestamp) {
		auto iter = mun[key].upper_bound(timestamp);
		/*这里使用了二分法，并且这里必须使用upper_bound(),
		因为题中有“如果有多个这样的值，则返回对应最大的timestamp_prev的那个值。”这个条件
		iter的位置，恰好是最大值的下一个位置
		*/
		return iter == mun[key].end() ? prev(iter)->second : (iter == mun[key].begin() ? "" : prev(iter)->second);
		/*这里也可以使用 return iter == mun[key].begin() ? "" : prev(iter)->second;  不过个人认为不好理解*/
		/*使用上面这种方法：表示如果在map容器中没有找到不小于timestamp的值，表示map容器中的值都满足题目，
		则我们只需要取前一位置的值。
		如果找到了，则我们首先需要判断，找到的位置是不是在map的第一个位置，如果在，则表示map中的元素都不满足题目，则输出""
		如果不在，表示iter前一位置的值是满足题目的。
		*/
	}
private:
	map<string, map<int, string> > mun;//存储set()函数的map容器
};