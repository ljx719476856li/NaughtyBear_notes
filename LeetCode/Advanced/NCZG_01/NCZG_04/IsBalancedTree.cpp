#include <iostream>
#include <algorithm>
using namespace std;

/*
题目：判断一棵二叉树是否是平衡二叉树(什么是平衡二叉树  就是在这棵树里面任何一个节点 他的左子树和右子树的高度差 不超过1 这就是平衡二叉树)
思路：判断一棵树是否是平衡二叉树，最简单的做法就是:
		(1) 就是递归函数很好用，因为递归函数会回到一个节点三次
			i). 例如头节点x ，第一次会来到x，先去x的左子树，回到x，再去x的右子树，又回到x，一共三次
			ii). 既然能收集节点信息三次，就可以先收集左子树的信息，再收集右子树的信息，然后整合判断符合平衡二叉树的条件不
				a). 判断左子树是否是平衡的
				b). 判断右子树是否是平衡的
				c). 判断左子树和右子树的高度是否 <= 1
			iii). 如果以每一个节点作为树的头节点都满足以上a), b), c)三条件，则都具有平衡性，那么整体就是平衡二叉树
		(2). 递归形式 —> 设计结构 —> 子树返回值设定(返回值需要包含：子树是否是平衡二叉树、树的高度)
*/

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data) :value(data), left(nullptr), right(nullptr) {}
};
struct ReturnTreeData
{
	bool isBlanced; //子树是否平衡
	int treeHeight; //子树的高度

	ReturnTreeData(bool isB, int h) : isBlanced(isB), treeHeight(h) {}
};

class IsBalancedTree
{
private:
	//判断平衡二叉树的信息处理递归
	//parameter：二叉树的头节点
	//return：返回的是子树/整颗二叉树的信息，具体信息看结构体ReturnTreeData
	ReturnTreeData* Process(Node* node);
public:
	//判断是否是平衡二叉树
	//parameter：需要判断树的头节点
	//return：true 表示是平衡二叉树，反之亦然
	bool IsBalanceTree(Node* node);
};

bool IsBalancedTree::IsBalanceTree(Node* node)
{
	return Process(node)->isBlanced;
}

ReturnTreeData* IsBalancedTree::Process(Node* node)
{
	if (node == nullptr)
		return new ReturnTreeData(true, 0); //空树也是平衡的，递归出口

	ReturnTreeData* left = Process(node->left);
	if (!left->isBlanced)
		return new ReturnTreeData(false, 0);

	ReturnTreeData* right = Process(node->right);
	if (!right->isBlanced)
		return new ReturnTreeData(false, 0);

	if (abs(left->treeHeight - right->treeHeight) > 1)
		return new ReturnTreeData(false, 0);

	return new ReturnTreeData(true, max(left->treeHeight, right->treeHeight) + 1);
}

int main()
{
	Node* node = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(4);
	node->left->right = new Node(5);
	node->right->left = new Node(6);
	node->right->right = new Node(7);
	node->right->right->left = new Node(8);
	node->right->right->right = new Node(2);
	node->right->right->right->left = new Node(2);


	IsBalancedTree sln;
	bool isB = sln.IsBalanceTree(node);
	cout << (isB ? "Is Balanced Tree" : "Is Not Balanced Tree");

	return 0;
}