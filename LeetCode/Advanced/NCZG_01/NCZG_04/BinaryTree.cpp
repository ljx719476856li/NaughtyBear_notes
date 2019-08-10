#include <iostream>
#include <stack>
using namespace std;


class PreInPosTraversal
{
public:
	struct Node
	{
		int value;
		Node* left;
		Node* right;

		Node(int data) :value(data), left(nullptr), right(nullptr) {}
		Node& operator = (const Node& node)
		{
			this->value = node.value;
			this->right = node.right;
			this->left = node.left;

			return *this;
		}

	};

	void preOrderUnRecur(Node* head);
	void inOrderUnRecur(Node* head);
	void posOrderUnRecur(Node* head);

	void preOrderRecur(Node* head);
	void inOrderRecur(Node* head);
	void posOrderRecur(Node* head);
};

void PreInPosTraversal::preOrderRecur(Node* head)
{
	if (head == nullptr)
		return;

	cout << head->value << " ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
void PreInPosTraversal::inOrderRecur(Node* head)
{
	if (head == nullptr)
		return;

	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}
void PreInPosTraversal::posOrderRecur(Node* head)
{
	if (head == nullptr)
		return;

	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << " ";
}

void PreInPosTraversal::preOrderUnRecur(Node* head)
{
	cout << "pre-order: ";
	if (head != nullptr)
	{
		stack<Node*> stack;
		stack.push(head);
		while (!stack.empty())
		{
			head = stack.top();
			cout << head->value << " ";
			stack.pop();
			if (head->right != nullptr)
				stack.push((head->right));
			if (head->left != nullptr)
				stack.push((head->left));
		}
		cout << "\n";
	}
}
void PreInPosTraversal::inOrderUnRecur(Node* head)
{
	cout << "in-order: ";
	if (head != nullptr)
	{
		stack<Node*>  stack;
		while (!stack.empty() || head != nullptr)
		{
			if (head != nullptr)
			{
				stack.push(head);
				head = head->left;
			}
			else
			{
				head = stack.top();
				cout << head->value << " ";
				head = head->right;
				stack.pop();
			}
		}
		cout << "\n";
	}


}
void PreInPosTraversal::posOrderUnRecur(Node* head)
{
	cout << "pos-order";
	if (head != nullptr)
	{
		stack<Node*> stack1;
		stack<Node*> stack2;
		stack1.push(head);
		while (!stack1.empty())
		{
			head = stack1.top();
			stack2.push(head);
			stack1.pop();
			if (head->left != nullptr)
				stack1.push(head->left);
			if (head->right != nullptr)
				stack1.push(head->right);
		}

		while (!stack2.empty())
		{
			cout << stack2.top()->value << " ";
			stack2.pop();
		}
		cout << "\n";
	}

}

//using BTree = PreInPosTraversal::Node;
//int main()
//{
//	BTree* head = new BTree(1);
//	head->left = new BTree(2);
//	head->right = new BTree(3);
//	head->left->left = new BTree(4);
//	head->left->right = new BTree(5);
//	head->right->left = new BTree(6);
//	head->right->right = new BTree(7);
//
//
//	//BTree* head = new BTree(5);
//	//head->left = new BTree(3);
//	//head->right = new BTree(8);
//	//head->left->left = new BTree(2);
//	//head->left->right = new BTree(4);
//	//head->left->left->left = new BTree(1);
//	//head->right->left = new BTree(7);
//	//head->right->left->left = new BTree(6);
//	//head->right->right = new BTree(10);
//	//head->right->right->left = new BTree(9);
//	//head->right->right->right = new BTree(11);
//
//	PreInPosTraversal ppt;
//	ppt.preOrderUnRecur(head);
//	ppt.inOrderUnRecur(head);
//	ppt.posOrderUnRecur(head);
//	
//	ppt.preOrderRecur(head);
//	cout << "\n";
//	ppt.inOrderRecur(head);
//	cout << "\n";
//	ppt.posOrderRecur(head);
//	cout << "\n";
//	return 0;
//}