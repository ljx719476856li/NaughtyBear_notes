#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data):value(data), left(nullptr), right(nullptr){}
};

class IsBalancedTree
{
public:
};