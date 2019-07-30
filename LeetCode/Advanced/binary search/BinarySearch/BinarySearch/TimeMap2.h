#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
	using psi = pair<string, int>;
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		auto &kv = m[key];
		kv.push_back({value, timestamp});
	}

	string get(string key, int timestamp) {
		auto itr = m.find(key);
		if (itr == m.end()) return "";
		auto &v = itr->second;
		int l = 0, r = v.size() - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (v[mid].second <= timestamp) l = mid + 1;
			else r = mid - 1;
		}
		if (r >= 0) return v[r].first;
		return "";
	}
	unordered_map<string, vector<psi>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
