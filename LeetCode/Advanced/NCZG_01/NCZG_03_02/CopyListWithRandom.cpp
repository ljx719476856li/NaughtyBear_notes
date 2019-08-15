#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	int var;
	Node* next;
	Node* random;
	Node() :var(0), next(nullptr), random(nullptr){}
	Node(int var) :var(var), next(nullptr), random(nullptr) {}
	Node(const Node& node) : var(node.var), next(node.next), random(node.random) {}
};

class CopyListWithRandom
{
public:
	Node* head;

	Node* CopyList1();
	Node* CopyList2();
};

/*
	思路：通过stl库中用hash_table作为底层实现的关联性容器，unordered_map<Key, Valule>设置了源节点与拷贝节点键值对的关系映射
		A). 通过循环遍历原链表给unordered_map赋值，key：原node， value：拷贝后的node
		B). 然后通过unordered_map的·Key获取到对应的value，即可做到拷贝
		C). 具体循环步骤如下(当pHead == nullptr结束循环)：
			a). copyListMap[pHead]->next = copyListMap[pHead->next];
			b). copyListMap[pHead]->parent = copyListMap[pHead->parent];
			c)	pHead = pHead->next;

1). 问题1
	while (pHead != nullptr)
	{
		copyListMap[pHead] = &Node(*pHead);
		pHead = pHead->next;
	}
	之后，，，对应的在copyListMap中的所有拷贝节点的值每次都会被修改为最新的，，由于每次&Node(*pHead)所获取的地址是新的
2). 问题2
	使用拷贝构造函数，遍历链表创建新的节点
*/
Node* CopyListWithRandom::CopyList1()
{
	unordered_map<Node*, Node*> copyListMap;
	Node* pHead = head;
	while (pHead != nullptr)
	{
		//copyListMap[pHead] = &Node(*pHead); wrong

		/*int value = pHead->var;
		Node* copyNode = new Node(value);
		copyListMap[pHead] = copyNode;   right but to long*/

		copyListMap[pHead] = new Node(/**pHead*/pHead->var); //simple
		pHead = pHead->next;
	}

	pHead = head;
	pHead->next = nullptr;
	while (pHead != nullptr)
	{
		//pHead->next
		copyListMap[pHead]->next = copyListMap[pHead->next];
		copyListMap[pHead]->random = copyListMap[pHead->random];
		pHead = pHead->next;
	}

	return copyListMap[head];
}

/*
	思路：方法1，会使额外空间复杂度为O(N)，由于链表是很简单的结构，因此可以不通过建立哈希map解决问题
		A). 原链表：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> nullptr
		B). 改造为：1 -> 1' -> 2 -> 2' -> 3 -> 3' ...... 8 -> 8' -> nullptr
		C). 此时即可知道每个原节点的next就是拷贝节点
		D). 问题即可解决，且此时的额外空间复杂度为O(1)
*/
Node* CopyListWithRandom::CopyList2()
{
	Node* pHead = head;
	
	//B)步骤 改造链表
	while (pHead != nullptr)
	{
		Node* temp = pHead->next;
		pHead->next = new Node(pHead->var);
		pHead->next->next = temp;
		pHead = temp;
	}

	pHead = head;
	Node* curCopy;
	while (pHead != nullptr)
	{
		Node* temp = pHead->next->next;
		curCopy = pHead->next;
		curCopy->random = pHead->random != nullptr ? pHead->random->next : nullptr;
		pHead = temp;
		/*
		Node* temp = pHead->next; //拷贝节点
		if(temp->random != nullptr)
			temp->random = temp->random->next; //创建random连接
		pHead = temp->next;
		*/
	}

	pHead = head;
	Node* res = head->next;
	while (pHead != nullptr)
	{
		Node* temp = pHead->next->next != nullptr ? pHead->next->next : nullptr;
		curCopy = pHead->next;
		pHead->next = temp;
		curCopy->next = temp != nullptr ? temp->next : nullptr;
		pHead = temp;
		//temp = pHead->next;
		//pHead->next = temp->next;
		//temp->next = pHead->next->next;
		//pHead = pHead->next;
	}

	return res;
}

/*
int main()
{
	CopyListWithRandom sln;

	sln.head = new Node(1);
	sln.head->next = new Node(2);
	sln.head->next->next = new Node(3);
	sln.head->next->next->next = new Node(4);
	sln.head->next->next->next->next = new Node(5);
	sln.head->next->next->next->next->next = new Node(6);

	sln.head->random = sln.head->next->next->next->next->next; // 1 -> 6
	sln.head->next->random = sln.head->next->next->next->next->next; // 2 -> 6
	sln.head->next->next->random = sln.head->next->next->next->next; // 3 -> 5
	sln.head->next->next->next->random = sln.head->next->next; // 4 -> 3
	sln.head->next->next->next->next->random = nullptr; // 5 -> nullptr
	sln.head->next->next->next->next->next->random = sln.head->next->next->next; // 6 -> 4


	Node* res1 = sln.CopyList1();
	Node* res2 = sln.CopyList2();
	return 0;
}
*/