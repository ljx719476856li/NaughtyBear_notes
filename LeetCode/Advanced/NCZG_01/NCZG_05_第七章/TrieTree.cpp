#include <iostream>
#include<vector>
using namespace std;

/*
题目：如何生成前缀树
	(1) 完成insert函数
	(2) 查找字符串
		i). 查找字符串出现了几次
		ii). 查找字符串是否出现
	(3) 删除字典树中存在的字符串
		i). 如何插入如何删除
		ii). 当词频已经只有一个了(遇到路径path自减为0后)，直接将next后半段设置为nullptr
	 (4) 前缀数量
*/

struct TrieNode
{
	int path;
	int end;
	vector<TrieNode*> nexts;

	TrieNode() :path(0), end(0), nexts(26) {}
};

class Trie
{
public:
	TrieNode* root;
	Trie() { root = new TrieNode(); }

	void Insert(const string& word);
	bool IsExist(const string& word);
	int CntSearch(const string& word);
	void Delete(const string& word);
	int prefixNumber(const string& word);
};

int Trie::prefixNumber(const string& word)
{
	if (word.empty())
		return 0;

	TrieNode* node = root;
	int idx;
	for (char ch: word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return 0;
		
		node = node->nexts[idx];
	}
	return node->path;
}

void Trie::Delete(const string& word)
{
	if (word.empty())
		return;
	TrieNode* node = root;
	//unique_ptr<TrieNode> node = make_unique<TrieNode>(root);
	int idx = 0;
	for (auto ch : word)
	{
		idx = ch - 'a';
		if (--node->nexts[idx]->path == 0)
		{
			node->nexts[idx] = nullptr;
			return;
		}
		node = node->nexts[idx];
	}
	node->end--;
	return;
}

int Trie::CntSearch(const string& word)
{
	if (word.empty())
		return 0;

	int idx = 0;
	TrieNode* node = root;
	for (char ch : word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return 0;

		node = node->nexts[idx];
	}

	return node->end;
}

bool Trie::IsExist(const string& word)
{
	if (word.empty())
		return false;

	int idx = 0;
	TrieNode* node = root;
	for (char ch : word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return false;

		node = node->nexts[idx];
	}

	return true;
}

void Trie::Insert(const string& word)
{
	if (word.empty())
		return;

	int idx = 0;
	TrieNode* node = root;
	for (auto ch : word)
	{
		idx = ch - 'a'; //当字典树是由'a'-'z'组成时
		if (node->nexts[idx] == nullptr)
			node->nexts[idx] = new TrieNode();
		node = node->nexts[idx];
		node->path++;
	}
	node->end++;
	return;
}

int main()
{
	TrieNode* root = new TrieNode();

	Trie head;
	head.Insert("abc");
	head.Insert("abca");
	//head.Insert("abcs");
	//head.Insert("abcf");
	//head.Insert("abce");
	cout << "is exit " << (head.IsExist("abcs") ? "Exit" : "Inexistence") << endl;
	head.Delete("abcs");
	cout << "is exit " << (head.IsExist("abcs") ? "Exit" : "Inexistence") << endl;
	head.Delete("abc");
	cout << "Seach " << head.CntSearch("abc") << endl;
	cout << "CNT " << head.prefixNumber("abc") << endl;
	return 0;
}