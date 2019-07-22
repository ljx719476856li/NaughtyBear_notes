//*************************************
//时间：2019/7/21
//名称：前缀树（解法一） unordered_map
//*************************************
#pragma once
#include<iostream>
#include <unordered_map>

using namespace std;

class Trie
{
public:
	/** Initialize your data structure here. */
	Trie(): root_(new TrieNode()) {}

	/** Inserts a word into the trie. */
	void insert(string word) 
	{
		TrieNode* p = root_.get();
		for (const char c : word)
		{
			if (!p->children.count(c))
				p->children[c] = new TrieNode();
			p = p->children[c];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) const
	{
		const TrieNode* p = find(word);
		return p && p->is_word; //当p节点不为nullptr且is_word是true的情况返回真，否在返回false
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) const
	{
		return find(prefix) != nullptr; //find返回值不为nullptr则为真，否在为false
	}

private:
	struct TrieNode
	{
		TrieNode(): is_word(false) {} //无参构造函数
		~TrieNode()//必须带析构
		{
			for (auto& kv : children)
				if (kv.second) delete kv.second;
		}

		bool is_word;
		unordered_map<char, TrieNode*> children;
	};

	//找到前缀节点返回对应的节点，否在返回false
	const TrieNode* find(const string& prefix) const
	{
		const TrieNode* p = root_.get();
		for (const char c : prefix)
		{
			if(!p->children.count(c))
				return nullptr;
			p = p->children.at(c);
		}
		return p;
	}

	//前缀树根
	unique_ptr<TrieNode> root_;
};