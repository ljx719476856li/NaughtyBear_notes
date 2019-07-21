#include <iostream>
#include "NBS_Trie.h"

using namespace std;

void main()
{
	//创建测试对象
	unique_ptr<Trie> trie(new Trie());

	trie->insert("apple");
	bool isTrue = trie->search("apple");   // 返回 true
	isTrue = trie->search("app");     // 返回 false
	isTrue = trie->startsWith("app"); // 返回 true
	trie->insert("app");
	isTrue = trie->search("app");     // 返回 true

	isTrue = trie->search("apple");
	isTrue = trie->startsWith("bp");


	return;
}