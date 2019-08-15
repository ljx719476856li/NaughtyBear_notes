#include <iostream>
using namespace std;

/*
题目：
1. 在二叉树的中序遍历的序列中，node的下一个节点叫做node的后继节点。在二叉树中找到一个节点的后继节点
2. 在二叉树的中序遍历的序列中，node的上一个节点叫做node的后继节点。在二叉树中找到一个节点的前继节点

思路：
（1）寻找一个节点在二叉树，中序遍历中的后继节点，分为两种情况(中序遍历特点：左 中 右)
	1). 当前节点有右子树时，后继节点一定会是当前节点的右子树的最左子叶
	2). 当前节点没有右子树时，通过parent节点往上一移动curNode，curNode的parent，当parent节点的左节点是curNode时，parent即为当前节点的后继节点(此处的curNode不一定是当前节点)
		i). curNode = parent;  parent = curNode.parent; ——> 通过parent节点往上一移动curNode，curNode的parent
		ii). 注意边界，parent != nullptr；

（2）寻找一个节点在二叉树，中序遍历中的前继节点，分为两种情况(中序遍历特点：左 中 右)
	1). 当前节点有左子树时，前继节点一定会是当前节点的左子树的最右子叶
	2). 当前节点没有左子树时，通过parent节点往上一移动curNode，curNode的parent，当parent节点的右节点是curNode时，parent即为当前节点的前继节点
*/

struct Node
{
public:
	int value;
	Node* parent;
	Node* left;
	Node* right;
	Node() :value(-1), parent(nullptr), right(nullptr), left(nullptr) {}
	Node(int data) :value(data), parent(nullptr), right(nullptr), left(nullptr) {}
};

class SuccessorNode
{
public:
	Node* getSuccessorNode(Node* node);
	Node* getLeftMost(Node* node);
};

Node* SuccessorNode::getSuccessorNode(Node* node)
{
	if (node == nullptr)
		return nullptr;

	if (node->right != nullptr)
		return getLeftMost(node->right);
	else
	{
		Node* parent = node->parent;
		if (parent->left == node)
			return parent;
		else
		{
			while (parent != nullptr && parent->left != node)
			{
				node = parent;
				parent = node->parent;
			}
			return parent;
		}
		
	}

}

Node* SuccessorNode::getLeftMost(Node* node)
{
	if (node == nullptr)
		return nullptr;
	
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}

int main()
{
	Node* head = new Node(6);
	head->parent = nullptr;
	head->left = new Node(3);
	head->left->parent = head;
	head->left->left = new Node(1);
	head->left->left->parent = head->left;
	head->left->left->right = new Node(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new Node(4);
	head->left->right->parent = head->left;
	head->left->right->right = new Node(5);
	head->left->right->right->parent = head->left->right;
	head->right = new Node(9);
	head->right->parent = head;
	head->right->left = new Node(8);
	head->right->left->parent = head->right;
	head->right->left->left = new Node(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new Node(10);
	head->right->right->parent = head->right;

	SuccessorNode sn;

	Node* test = head->left->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->left->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->right->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->left->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->right; // 10's next is null
	//cout << test->value << " next: " << sn.getSuccessorNode(test)->value;
	//System->out->println(test->value + " next: " + sn.getSuccessorNode(test));

	return -1;
}