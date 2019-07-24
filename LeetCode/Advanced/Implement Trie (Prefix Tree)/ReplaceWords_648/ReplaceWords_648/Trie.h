//*************************************
//时间：2019/7/23
//名称：648. 单词替换
//思路：
/*
这道题给了我们一个前缀字典，又给了一个句子，让我们将句子中较长的单词换成其前缀(如果在前缀字典中存在的话)。
我们对于句子中的一个长单词如何找前缀呢，是不是可以根据第一个字母来快速定位呢，比如cattle这个单词的首字母是c，那么我们在前缀字典中找所有开头是c的前缀
*/
//**********************************

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	class TrieNode {
	public:
		bool isWord;
		TrieNode *child[26];
		TrieNode() : isWord(false) {
			for (auto &a : child) a = NULL;
		}
		~TrieNode() 
		{
			for (TrieNode* children : child)
			{
				if(children) delete children;
			}
		}
	};

	string replaceWords(vector<string>& dict, string sentence) {
		string res = "", t = "";
		istringstream is(sentence);
		TrieNode *root = new TrieNode();
		for (string word : dict) {
			insert(root, word);
		}
		while (is >> t) {
			if (!res.empty()) res += " ";
			res += findPrefix(root, t);
		}
		return res;
	}

	void insert(TrieNode* node, string word) {
		for (char c : word) {
			if (!node->child[c - 'a']) node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->isWord = true;
	}

	string findPrefix(TrieNode* node, string word) {
		string cur = "";
		for (char c : word) {
			if (!node->child[c - 'a']) break;
			cur.push_back(c);
			node = node->child[c - 'a'];
			if (node->isWord) return cur;
		}
		return word;
	}
};