#include <queue>
#include "PrintBinaryTree.hpp"

/*
题目：二叉树的序列化与反序列化
思路：使用前序，中序，后序，层序等遍历二叉树的方法，序列化二叉树为字符串作为记录，然后又通过相同的方法对字符串反序列化构造回二叉树
		1). 前序遍历
			i). 先序遍历二叉树，把所有节点记录到字符串中去，包括空节点(#表示空节点)，_下划线作为每个节点间的分隔符
			ii). 最后组合而成的字符串，就是对二叉树的序列化结果
			iii). 反序列化，即为对序列化的输出结果进行相同的前序递归操作，即可还原整棵二叉树的结构
				a). 通过分解字符串，分离出对应的字符串数组，保存每一个节点的信息
				b). 通过队列来存储，每个节点的信息(队列压入弹出的顺序，先进先出，符合重构二叉树的要求)
				c). 从队列中取出节点信息，使用与前序遍历顺序相同的方式递归连接

		2). 中序，后续遍历类似
		3). 特别提出，层序遍历概念
*/

struct Node : public Nodee
{
	Node(int data) : Nodee(data) {}
};

class SerializeAndReconsturctTrees
{
public:
	//二叉树的序列化
	//parameter：需要序列化二叉树的头节点
	//return：string类型的字符串
	string SerializeByTree(Nodee* head);

	//处理序列化字符信息，分解到对应的队列中存储
	//parameter：序列化字符串
	//return：返回重构二叉树的根节点
	Node* ReconByPreString(string str);

	Node* ReconPreOrder(queue<string> preQueue);

};

string SerializeAndReconsturctTrees::SerializeByTree(Nodee* head)
{
	if (head == nullptr)
		return "#_"; //空节点也应记录

	string res = to_string(head->value); //通过_下划线作为分隔符
	res.append("_");
	res += SerializeByTree(head->left);
	res += SerializeByTree(head->right);

	return res;
}

Node* SerializeAndReconsturctTrees::ReconByPreString(string preStr)
{
	vector<string> values(3);
	SplitString(preStr, values, "_");
	queue<string> queueStr;
	for (int i = 0; i <values.size(); i++)
		queueStr.push(values[i]);

	return ReconPreOrder(queueStr);
}

Node* SerializeAndReconsturctTrees::ReconPreOrder(queue<string> preQueue)
{
	string value = preQueue.front();
	preQueue.pop();
	//当获取到#时，便可返回了

	
	//Node* head = new Node(static_cast<int>(strtol(value.c_str(), &end, 16)););
		ReconPreOrder(preQueue)
}
int main()
{
	PrintBinaryTree pbt;

	Node* head;
	head = new Node(100);
	head->left = new Node(21);
	head->left->left = new Node(37);
	head->right = new Node(-42);
	head->right->left = new Node(0);
	head->right->right = new Node(666);
	pbt.printTree(head);

	SerializeAndReconsturctTrees sart;
	string res = sart.SerializeByTree(head);
	cout << res << endl;

	return 0;
}
