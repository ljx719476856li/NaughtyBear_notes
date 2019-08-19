#include <iostream>
using namespace std;

/*
题目：已知一棵完全二叉树，求其节点的个数。要求时间复杂度低于O(N),N为这颗二叉树的节点数
思路：通过分别遍历二叉树左右边界，分别获得信息，左子树的层级(通过遍历左子树的左边界获得)，右子树的层级(通过遍历右子树的左边界获得)
	(1) 首先遍历该树的左边界，获得左子树高度
		i). 因为该树是完全二叉树，所以完全遍历完这棵树的左边界，即可获得高度
	(2) 然后遍历该树的右边界，同理，获得右边界层级
		i). 如果右边界层级等于左边界层级，则左子树一定是满二叉树
		ii). 如果右边界层级不能到达左边界层级，则左子树不一定是满二叉树，但右子树一定是满二叉树
	(3) 通过满足不同条件，有不同的处理结果
		i). 满足条件i)，则可求出左子树的节点个数为2^n - 1(n为左子树的层级数)，然后再递归去求右子树的节点个数
		i). 满足条件ii)，则可求出右子树的节点个数为2^n(n为右子树的节点个数)，然后再去递归求左子树的节点个数
	
时间复杂度是 log(n平方)
	第一个logN是 需要遍历多少个节点
	第二个logN是 遍历的边界
*/
struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data): value(data), left(nullptr), right(nullptr){}
};

class CBTNodeNum
{
public:
	//获得二叉树的节点数
	int GetNodeNum(Node* head);
private:
	//递归函数
	//parameter：head 当前节点，level 当前节点的所处层数，depth 当前节点的左子树的深度
	//return：返回以当前子节点为头的子树的节点数
	int BSProcess(Node* head, int level, int depth);
	//获得左子树的深度
	//parameter：head 当前节点，level 当前节点所处层数
	//return：返回当前节点的左子树的深度
	int LeftLevel(Node* head, int level);

};
int CBTNodeNum::GetNodeNum(Node* head)
{
	if (head == nullptr)
		return 0; //空树也是完全二叉树

	return BSProcess(head, 1, LeftLevel(head, 1));
}

int CBTNodeNum::BSProcess(Node* head, int level, int depth)
{
	//递归出口
	if (level == depth)
		return 1; //当层级level 已经 达到 子树深度时，证明到达叶节点了
	

	//右子树的深度不能达到左边界的层级深度，则右子树一定是满二叉树
	if (LeftLevel(head->right, level + 1) != depth)
		return (1 << depth - level - 1) + BSProcess(head->left, level + 1, depth);
	else //右子树的深度达到左边界的层级深度，则左子树一定是满二叉树
		return (1 << depth - level) + BSProcess(head->right, level + 1, depth);
}

int CBTNodeNum::LeftLevel(Node* head, int level)
{
	while (head != nullptr)
	{
		level++;
		head = head->left;
	}

	return level - 1; //返回左子树的深度，所以剪掉当前节点的那层 ‘1’
}

int main()
{
	//int num = 0;
	//// << 左移
	//num = 3 << 2;
	//// >> 右移
	//num = num >> 2;
	Node* node2 = new Node(5);
	node2->left = new Node(3);
	node2->right = new Node(8);
	node2->left->left = new Node(2);
	node2->left->right = new Node(4);
	node2->right->left = new Node(6);
	node2->left->left->right = new Node(7);
	node2->right->right = new Node(8);
	node2->left->left->left = new Node(9);
	node2->left->right->left = new Node(10);

	CBTNodeNum sln;
	int res = sln.GetNodeNum(node2);

	cout << " 结果：" << res << endl;
	return 0;
}