//Code_14_FindFirstIntersectNode
#include <iostream>
using namespace std;

struct Node
{
public:
	int var;
	Node* next;
	Node() : var(0), next(nullptr) {}
	Node(int data) : var(data), next(nullptr) {}
};

/*
	思路：题目可知，单链表，俩链表可能有环，也可能无环，由此可能出现的拓扑结构
		a). —< // >—  (两个链表都没有环的情况)
		b). —○ 与 —     (两个链表一个有环，一个没有环)
		c). —○ 与 —○  // >—○ // >○
	A). 其中 a) ，由图可知，当两个链表都没有环的情况，存在两链表相交的拓扑结构，
		1)  由此出发，可以获得的条件，遍历head1(len1, end1)，head2(len2, end2)
		2)  遍历结束后，通过比较end1与end2可得知(此处end1，与end2表示的是尾部节点的内存地址)：
			(1)  end1 == end2 两个链表必定相交，但是相交的第一个节点不一定是尾部节点
				使用len1和len2了  如果len1=100 len2=80  head1先走20步 然后head2开始随head1起步， 并且一定会共同走到第一个相交的节点处
			(2) end2 != end1 俩链表必不会相交，因为俩单链表结构不可能出现 ×(交叉) 这种结构
	B). 其中 b)，由图可知，当两个链表一个有环，一个没有环的时候，必定不会出现相交情况。(单链表结构特性，类比绳子)
	C). 其中 c)，由图可知，当两个链表都带有环时，必定会出现上述三种拓扑结构
		1)  由此出发，可以获得的条件，遍历head1(len1, loop1)，head2(len2, loop2)
		1)  如果 loop1 == loop2必为 >—○  拓扑结构
		2) 如果loop1 != loop2 必为 —○ 与 —○ // >○ 拓扑结构
*/

class FindFirstInterserct
{
public:
	Node* GetInterserctNode();
	
	Node* head1;
	Node* head2;

private:
	Node* GetLoopNode(Node* head);
	Node* NoLoop();
	Node* BothLoop(Node* loop1, Node* loop2);
};

Node* FindFirstInterserct::GetInterserctNode()
{
	//此边界不可忘记判断
	if (head1 == nullptr && head2 == nullptr)
		return nullptr;

	Node* loop1 = GetLoopNode(head1);
	Node* loop2 = GetLoopNode(head2);

	if (loop1 == nullptr && loop2 == nullptr)
		return NoLoop();
	else if (loop1 != nullptr && loop2 != nullptr)
		return BothLoop(loop1, loop2);

	return nullptr;
}

Node* FindFirstInterserct::GetLoopNode(Node* head)
{
	Node* fast = head, *slow = head;

	//快慢指针的相遇，有环
	while (fast != slow)
	{
		if (fast == nullptr && fast->next->next == nullptr)
			return nullptr;

		fast = fast->next->next;
		slow = slow->next;
	}
	fast = head;
	//此处相遇，必定是入环的第一个节点
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}
//两个链表没环
Node* FindFirstInterserct::NoLoop()
{	
	Node* end1 = nullptr, *end2 = nullptr;
	int subtractLen = 0;

	Node* pHead1 = head1, *pHead2 = head2;
	while (pHead1 != nullptr)
	{
		subtractLen++;
		if (pHead1->next == nullptr)
			end1 = pHead1;
		pHead1 = pHead1->next;
	}
	while (pHead2 != nullptr)
	{
		subtractLen--;
		if (pHead2->next == nullptr)
			end2 = pHead2;
		pHead2 = pHead2->next;
	}
	if (end1 != end2)
		return nullptr;


	pHead1 = subtractLen > 0 ? head1 : head2;
	pHead2 = head1 == pHead1 ? head2 : head1;

	subtractLen = abs(subtractLen);
	while (subtractLen > 0)
	{
		pHead1 = pHead1->next;
		subtractLen--;
	}
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}

	return pHead1;

}
//两个链表都有环
Node* FindFirstInterserct::BothLoop(Node* loop1, Node* loop2)
{
	if (loop1 == loop2)
	{
		//模仿NoLoop的操作
		Node* cur1 = head1;
		Node* cur2 = head2;
		int subtractLen = 0;
		while (cur1 != loop1)
		{
			subtractLen++;
			cur1 = cur1->next;
		}
		while (cur2 != loop2)
		{
			subtractLen--;
			cur2 = cur2->next;
		}
		
		cur1 = subtractLen > 0 ? head1 : head2;
		cur2 = head1 == cur1 ? head2 : head1;
		subtractLen = abs(subtractLen);
		while (subtractLen > 0)
		{
			cur1 = cur1->next;
			subtractLen --;
		}

		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else //loop1 != loop2，通过遍历loop1判断是那个拓扑结构
	{
		Node* temp = loop1->next;
		while (temp != loop1)
		{
			if (temp = loop2)
				return loop2;
			temp = temp->next;
		}
		return nullptr;
	}
}


int main()
{
	FindFirstInterserct sln;

	// 1->2->3->4->5->6->7->null
	sln.head1 = new Node(1);
	sln.head1->next = new Node(2);
	sln.head1->next->next = new Node(3);
	sln.head1->next->next->next = new Node(4);
	sln.head1->next->next->next->next = new Node(5);
	sln.head1->next->next->next->next->next = new Node(6);
	sln.head1->next->next->next->next->next->next = new Node(7);

	// 0->9->8->6->7->null
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next->next->next->next->next; // 8->6
	

	// 1->2->3->4->5->6->7->4->->->
	sln.head1 = new Node(1);
	sln.head1->next = new Node(2);
	sln.head1->next->next = new Node(3);
	sln.head1->next->next->next = new Node(4);
	sln.head1->next->next->next->next = new Node(5);
	sln.head1->next->next->next->next->next = new Node(6);
	sln.head1->next->next->next->next->next->next = new Node(7);
	sln.head1->next->next->next->next->next->next = sln.head1->next->next->next; // 7->4

	// 0->9->8->2->->->
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next; // 8->2
	//System->out->println(getIntersectNode(sln.head1, sln.head2)->value);

	// 0->9->8->6->4->5->6->->
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next->next->next->next->next; // 8->6
	//System->out->println(getIntersectNode(sln.head1, sln.head2)->value);
	return 0;
}
