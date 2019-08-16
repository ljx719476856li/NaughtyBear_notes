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
	Nodee* ReconByPreString(string str);

	Nodee* ReconPreOrder(queue<string> preQueue);


	string serialByPre(Nodee* head);
	Nodee* reconByPreString(string preStr);
	Nodee* reconPreOrder(queue<string> queue);

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

Nodee* SerializeAndReconsturctTrees::ReconByPreString(string preStr)
{
	vector<string> values;
	SplitString(preStr, values, "_");
	queue<string> queueStr;
	for (int i = 0; i <values.size(); i++)
		queueStr.push(values[i]);

	return ReconPreOrder(queueStr);
}

Nodee* SerializeAndReconsturctTrees::ReconPreOrder(queue<string> preQueue)
{
	string value = preQueue.front();
	preQueue.pop();
	//当获取到#时，便可返回了
	if (value._Equal("#"))
	{
		return nullptr;
	}

	
	Nodee* head = new Nodee(atoi(value.c_str()));
	//Nodee* head = new Nodee(static_cast<int>(strtol(value.c_str(), &end, 16)););
	head->left = ReconPreOrder(preQueue);
	head->right = ReconPreOrder(preQueue);

	return head;
}

string SerializeAndReconsturctTrees::serialByPre(Nodee* head) {
	if (head == nullptr) {
		return "#!";
	}
	string res = to_string(head->value) + "!";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}

Nodee* SerializeAndReconsturctTrees::reconByPreString(string preStr) {
	vector<string> values;
	SplitString(preStr, values, "!");
	queue<string> queue;
	for (int i = 0; i != values.size(); i++) {
		queue.push(values[i]);
	}
	return reconPreOrder(queue);
}

Nodee* SerializeAndReconsturctTrees::reconPreOrder(queue<string> queue) {
	string value = queue.front();
	queue.pop();
	if (value._Equal("#")) {
		return nullptr;
	}
	Nodee* head = new Nodee(atoi(value.c_str()));
	head->left = reconPreOrder(queue);
	head->right = reconPreOrder(queue);
	return head;
}

/*
int main()
{
	PrintBinaryTree pbt;

	Nodee* head;
	head = new Nodee(100);
	head->left = new Nodee(21);
	head->left->left = new Nodee(37);
	head->right = new Nodee(-42);
	head->right->left = new Nodee(0);
	head->right->right = new Nodee(666);
	pbt.printTree(head);

	SerializeAndReconsturctTrees sart;
	string res = sart.serialByPre(head);
	cout << res << endl;
	Nodee* head2 = sart.reconByPreString(res);
	pbt.printTree(head2);

	return 0;
}
*/
