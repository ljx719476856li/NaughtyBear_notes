//*************************************
//时间：2019/7/23
//名称：648. 单词替换
//思路:
/*
这道题给了我们一个前缀字典，又给了一个句子，让我们将句子中较长的单词换成其前缀(如果在前缀字典中存在的话)。
我们对于句子中的一个长单词如何找前缀呢，是不是可以根据第一个字母来快速定位呢，比如cattle这个单词的首字母是c，那么我们在前缀字典中找所有开头是c的前缀
*/
//*************************************

#pragma once
#include <iostream>
#include <sstream>
#include<algorithm>
#include <vector>

using namespace std;

class  Solution
{
public:
	string replaceWords(vector<string>& dict, string sentence)
	{
		//存放结果
		string res = "";
		string sTmp = "";
		//用于存放前缀单词的数组
		vector<vector<string>> vecDic(26);

		//由于C++中没有split函数，所以我们采用字符串流来提取每一个单词
		istringstream is(sentence);

		//题目中要求用最短的前缀来替换单词，所以通过sort排序将短前缀放在长前缀的前面
		sort(dict.begin(), dict.end(), [](string& a, string& b) { return a.size() < b.size(); });
		for (string word: dict)
			vecDic[word[0] - 'a'].push_back(word);

		//采用字符串流来提取每一个单词
		while (is >> sTmp)
		{
			for (string word: vecDic[sTmp[0] - 'a'])
			{
				if (sTmp.substr(0, word.size()) == word)
				{
					sTmp = word;
					break;
				}
			}
			res += sTmp + " ";
		}

		//去掉最后一个" "
		res.pop_back();
		return res;
	}
};
