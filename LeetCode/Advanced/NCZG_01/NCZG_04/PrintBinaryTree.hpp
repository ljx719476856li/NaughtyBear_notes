#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Nodee {
	int value;
	Nodee* left;
	Nodee* right;

	Nodee (int data) {
		this->value = data;
		left = nullptr;
		right = nullptr;
	}
};

class PrintBinaryTree {
public:
	void printTree(Nodee* head);

	void printInOrder(Nodee* head, int height, string to, int len);

	string getSpace(int num);
};

void PrintBinaryTree::printTree(Nodee* head) {
	//System->out->println("Binary Tree:");
	cout << "Binary Tree: " << endl;

	printInOrder(head, 0, "H", 17);
	//System->out->println();
	cout << endl;
}

void PrintBinaryTree::printInOrder(Nodee* head, int height, string to, int len) {
	if (head == nullptr) {
		return;
	}
	printInOrder(head->right, height + 1, "v", len);
	string val = to + to_string(head->value) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = getSpace(lenL) + val + getSpace(lenR);
	//System->out->println(getSpace(height * len) + val);
	cout << getSpace(height * len) + val << endl;
	printInOrder(head->left, height + 1, "^", len);
}

string PrintBinaryTree::getSpace(int num) {
	string space = " ";
	string buf;
	for (int i = 0; i < num; i++) {
		buf.append(space);
	}
	return buf;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}


