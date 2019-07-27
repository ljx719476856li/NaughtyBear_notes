#pragma once
#include <iostream>
using namespace std;
//Definition for singly - linked list.
//https://docs.google.com/spreadsheets/d/1SbpY-04Cz8EWw3A_LBUmDEXKUMO31DBjfeMoA0dlfIA/edit#gid=410905529

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class  Solution
{
public:
	//两数相加
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(-1), *cur = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			//获取到俩列表中的value值
			int val1 = l1 ? l1->val : 0; 
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry; //val1 + val2 + 进位(carry) = 此轮相同位数的和
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next; //cur指向下一位
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		if (carry) cur->next = new ListNode(1); //补充一个进位
		return dummy->next;
	}

	// 删除链表的倒数第N个节点
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		//所传过来的链表长度 > 1
		if (!head->next) 
			return nullptr;
		
		ListNode* cur = head, *pre = head;
		for (int i = 0; i < n; ++i)
			cur = cur->next;

		//删除的是头节点
		if (!cur) return head->next;
		//移动pre，以及cur，直到cur到结尾处
		while (cur->next)
		{
			cur = cur->next;
			pre = pre->next;
		}

		pre->next = pre->next->next;
		return head;
	}
	
	//两两交换链表中的节点
	ListNode* swapPairs(ListNode* head)
	{
		if (!head || !head->next)
			return head;

		//让tmp指针指向head->next
		ListNode* tmp = head->next;
		head->next = swapPairs(head->next->next);
		tmp->next = head;
		return tmp;
	}

	//反转链表
	//反转一个单链表
	ListNode* reverseList(ListNode* head) 
	{
		if (!head || !head->next) 
			return head;

		ListNode *newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}

};