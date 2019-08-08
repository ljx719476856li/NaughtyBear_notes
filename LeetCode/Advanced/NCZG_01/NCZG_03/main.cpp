#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//栈模拟队列
class Queue
{
public:
	stack<int> m_stackPush;
	stack<int> m_stackPop;
	
	void Push(int num);
	int Pop();
	int Peek();
	

private:
	void PoorOut();

};

void Queue::Push(int num)
{
	m_stackPush.push(num);

	PoorOut();
}

int Queue::Pop()
{
	if (m_stackPop.empty() && m_stackPush.empty())
		return -1;
	else if (m_stackPop.empty())
		PoorOut();
	
	int var = m_stackPop.top();
	m_stackPop.pop();
	return var;
}

int Queue::Peek()
{
	if (m_stackPop.empty() && m_stackPush.empty())
		return -1;
	else if (m_stackPop.empty())
		PoorOut();
	return m_stackPop.top();
}

void Queue::PoorOut()
{
	if (m_stackPop.size() > 0)
		return; //条件1，当Pop栈里还有元素时，Push栈不能往Pop栈放
	while (m_stackPush.size() > 0)
	{
		m_stackPop.push(m_stackPush.top());
		m_stackPush.pop();
	}
}

//队列模拟栈
class Stack
{
public:
	queue<int>* m_queueData;
	queue<int>* m_queueHelp;
	Stack()
	{
		m_queueData = new queue<int>;
		m_queueHelp = new queue<int>;
	}


	void Push(int num);
	int Pop();
	int Peek();

private:
	void Swap();
};

void Stack::Push(int num)
{
	m_queueData->push(num);
}
int Stack::Pop()
{
	if (m_queueData->empty() && m_queueHelp->empty())
		return -1;

	//将Data中的元素，放进Help中，直至size为1
	while (m_queueData->size() > 1)
	{
		m_queueHelp->push(m_queueData->front());
		m_queueData->pop();
	}

	int var = m_queueData->front();
	m_queueData->pop();
	Swap();
	return var;
}
int Stack::Peek()
{
	if (m_queueData->empty() && m_queueHelp->empty())
		return -1;

	//将Data中的元素，放进Help中，直至size为1
	while (m_queueData->size() > 1)
	{
		m_queueHelp->push(m_queueData->front());
		m_queueData->pop();
	}

	int var = m_queueData->front();
	m_queueHelp->push(var);
	m_queueData->pop();
	Swap();
	return var;
}
void Stack::Swap()
{
	queue<int>* temp = m_queueHelp;
	m_queueHelp = m_queueData;
	m_queueData = temp;
}

//for test
/*
int main()
{
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	int num1 = stack.Peek();
	num1 = stack.Pop();
	num1 = stack.Pop();
	num1 = stack.Pop();
	num1 = stack.Pop();
	num1 = stack.Pop();
	num1 = stack.Pop();

	Queue queue;
	queue.Push(1);
	queue.Push(2);
	queue.Push(3);
	queue.Push(4);
	queue.Push(5);

	int num2 = queue.Peek();
	num2 = queue.Pop();
	num2 = queue.Pop();
	num2 = queue.Pop();
	num2 = queue.Pop();
	num2 = queue.Pop();
	num2 = queue.Pop();
	num2 = queue.Pop();


	return 0;
}
*/