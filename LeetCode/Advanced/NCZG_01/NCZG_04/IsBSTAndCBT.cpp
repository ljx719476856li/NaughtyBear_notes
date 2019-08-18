#include <iostream>
#include <stack>
using namespace std;

/*
题目：判断一棵树是否是搜索二叉树
思路：
		(1) 什么是搜索二叉树
			i). 任何一个节点，为头的子树，左子树都比当前节点小，右子树都比他大
		(2) 如何判断？
			i). 二叉树中序遍历的结果 —> 中序遍历方式：左 中 右 —> 是否呈现依次升序的情况
		(3) 条件(2) 成立则当前二叉树是搜索二叉树(Binary Search Tree)

题目：判断一棵树是否是完全二叉树

思路：
		(1) 什么是完全二叉树
			i). 完全二叉树要么是一颗满的二叉树(任何一个非叶节点的孩子都是全的这就是满二叉树，满二叉树最底下一层都是叶节点)
			ii).从左到右，依次补齐的树，也是完全二叉树
		(2) 使用层序遍历判断是否是完全二叉树
			i). 一个节点有右孩子，但是没有左孩子
			ii). 不满足(1)时，一个节点的左右孩子不全在，则往后节点都必须是叶节点
		(3) 其中只要不满足条件(2)的二叉树即为完全二叉树(Completely Binary Tree)
*/

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data):value(data), left(nullptr), right(nullptr){}
};

class IsBSTAndCBT
{
public:
	bool IsCBTree(Node* head);
	bool IsBSTree(Node* head);
};
bool IsBSTAndCBT::IsCBTree(Node* head)
{
	//空树也是完全二叉树
	if (head == nullptr)
		return true;

	Node* left = nullptr;
	Node* right = nullptr;




}

bool IsBSTAndCBT::IsBSTree(Node* head)
{
	if (head == nullptr)
		return false;
	stack<Node*> help;
	bool res = false;
	int temp = INT_MIN;
	while (!help.empty() || head != nullptr)
	{
		if (head != nullptr)
		{
			help.push(head);
			head = head->left;
		}
		else
		{
			head = help.top();
			temp = (temp > head->value ? temp : head->value); //依次升序结果，temp应该小于head.value
			res = (temp == head->value ? true : false);

			help.pop();
			head = head->right;
		}
	}
	return res;
}

int main()
{
	Node* node = new Node(5);
	node->left = new Node(3);
	node->right = new Node(8);
	node->left->left = new Node(2);
	node->left->right = new Node(4);
	node->left->left->left = new Node(1);
	node->right->left = new Node(6);
	node->right->left->right = new Node(7);
	node->right->right = new Node(8);
	node->right->right->left = new Node(9);


	IsBSTAndCBT sln;
	bool res = sln.IsBSTree(node);
	cout << (res ? "BT is BST" : "BT is not BST");
	
	return 0;
}