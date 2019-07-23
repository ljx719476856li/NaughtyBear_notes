#pragma once

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	struct TrieNode
	{
	public:
		bool isWord;
		vector<TrieNode*> child;
		TrieNode() : isWord(false), child(26, nullptr) {}
		~TrieNode()
		{
			for (TrieNode* a : child)
			{
				if (a) delete a;
			}
		}

	};

	string replaceWords(vector<string>& dict, string sentence)
	{
		string res = "", t = "";
		istringstream is(sentence);
		TrieNode* root = new TrieNode();
		for (string word : dict)
			Insert(root, word);

		while (is >> t)
		{
			if (!res.empty())res += " ";
			res += SearchPrefix(root, t);
		}
		return res;
	}

private:
	void Insert(TrieNode* node, string word) {
		for (char c : word) {
			if (!node->child[c - 'a']) node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->isWord = true;
	}

	string SearchPrefix(TrieNode* node, string word) const
	{
		string tmp = "";
		for (char c : word)
		{
			if (!node->child[c - 'a']) break;
			tmp.push_back(c);
			node = node->child[c - 'a'];
			if (node->isWord)return tmp;
		}

		return word;
	}
};
