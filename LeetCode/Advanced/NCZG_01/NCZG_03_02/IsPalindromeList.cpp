#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
	int var;
	Node* next;
	Node() :var(0), next(nullptr) {}
	Node(int var) : var(var) {}
	Node(int var, Node* next) : var(var), next(nullptr) {}
};

class PalindromeList
{
public:
	bool IsPalindromeList_pen1();	
	bool IsPalindromeList_pen2();
	bool IsPalindromeList_interview();

private: 
	bool Cmp(stack<Node*> help)
	{
		Node* pHead = m_pHead;
		while (help.size() > 0)
		{
			if (pHead->var != help.top()->var)
				return false;
			pHead = pHead->next;
			help.pop();
		}
		return true;
	}
	int Size()
	{
		int length = 0;
		while (m_pHead->next)
			++length;
		return length;
	}

public:
	Node* m_pHead;
};

/*
思路：使用辅助栈来解决问题
			a). 通过把链表所有内容倒入栈中，然后通过栈的特性依次读取出来，和原链表作比较
			b). 通过快慢指针，快指针走两步，慢指针走一步。分情况处理：
				1) 当链表长度为偶数时，慢指针会停在中间的左边节点
				2) 当链表长度为奇数时，慢指针会停在中间节点
			c). 通过以上结果，将有半段加入栈中，然后通过栈的特行，一次将左右半段进行比较
上述时间复杂度都为：O(N)，额外空间复杂度O(N)
*/
bool PalindromeList::IsPalindromeList_pen1()
{
	//辅助栈
	stack<Node*> help;
	Node* pHead = m_pHead;
	while (pHead != nullptr)
	{
		help.push(pHead);
		pHead = pHead->next;
	}
	
	return Cmp(help);
}
bool PalindromeList::IsPalindromeList_pen2()
{
	if (m_pHead == nullptr || m_pHead->next == nullptr)
		return true;

	//辅助栈
	stack<Node*> help;
	Node* fast = m_pHead, *slow = m_pHead, *mid = nullptr;

	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	while (slow->next != nullptr)
	{
		help.push(slow->next);
		slow = slow->next;
	}

	return Cmp(help);
}

/* 
思路：通过改变有半段部分链表的指向解决问题
			A). 通过快慢指针，快指针走两步，慢指针走一步。分情况处理：
				a) 当链表长度为偶数时，慢指针会停在中间的左边节点
				b) 当链表长度为奇数时，慢指针会停在中间节点
			B). 通过以上结果，将有半段部分指针反向，再将慢指针指向的中间节点指向null
上述时间复杂度都为：O(N)，额外空间复杂度O(1)
*/
bool PalindromeList::IsPalindromeList_interview()
{
	if (m_pHead == nullptr || m_pHead->next == nullptr)
		return true;
	Node* fast = m_pHead, *slow = m_pHead;
	while (fast->next != nullptr && fast->next->next != nullptr) //找到中点
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = nullptr;
	Node* temp = nullptr;
	while (fast != nullptr)
	{
		temp = fast->next;
		fast->next = slow;
		slow = fast;
		fast = temp;
	}
	fast = m_pHead;
	temp = slow;
	while (fast != nullptr)
	{
		if (fast->var != slow->var)
			return false;
		fast = fast->next;
		slow = slow->next;
	}
	fast = temp->next;
	temp->next = nullptr;
	while (fast != nullptr)
	{
		slow = fast->next;
		fast->next = temp;
		temp = fast;
		fast = slow;
	}

	return true;
}

int main()
{
	PalindromeList sln;
	sln.m_pHead = new Node(1);
	sln.m_pHead->next = new Node(2);
	sln.m_pHead->next->next = new Node(3);
	sln.m_pHead->next->next->next = new Node(1, nullptr);
	//sln.m_pHead->next->next->next->next = new Node(1, nullptr);


	bool res1 = sln.IsPalindromeList_pen1();
	bool res2 = sln.IsPalindromeList_pen2();
	bool res3 = sln.IsPalindromeList_interview();
	return 0;
}