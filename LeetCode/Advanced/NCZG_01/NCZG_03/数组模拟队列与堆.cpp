#include<iostream>
using namespace std;


class Base
{
public:
	Base(size_t size): m_length(size)
	{
		m_arr = new int[size] {-1};
	}
	~Base()
	{
		if (m_arr != nullptr)
			delete m_arr;
		m_length = 0;
	}

public:
	virtual void Push(int num) {}
	virtual int Pop() { return -1; }
	virtual int Peek() { return -1; }
protected:
	int* m_arr;
	int m_length;
};

class Stack: Base
{
public:
	Stack(size_t size): Base(size), m_idx(0){}

	virtual void Push(int num) override;
	virtual int Pop() override;
	virtual int Peek() override;


private:
	int m_idx; //idx指的是下一个可以添加的位置，依赖：小于size
};

void Stack::Push(int num)
{
	if (m_idx >= m_length)
		return; //下一个添加位，已越界

	m_arr[m_idx++] = num;
}
int Stack::Pop()
{
	if (m_idx <= 0)
	{
		return -1; //弹出位，已经到达底部
	}

	return m_arr[--m_idx];
}
int Stack::Peek()
{
	if (m_idx <= 0)
	{
		return -1; //获取位，已经到达底部
	}

	return m_arr[m_idx - 1];
}

class Queue: Base
{
public:
	Queue(size_t size) :Base(size), m_end(0), m_start(0), m_size(0) {}

	virtual void Push(int num) override;
	virtual int Pop() override;
	virtual int Peek() override;

private:
	int m_end;
	int m_start;
	int m_size;
};

void Queue::Push(int num)
{
	if (m_size >= m_length)
		return; //队列已经满了，无法进队列

	m_size++;
	m_arr[m_end] = num;
	m_end = m_end == m_length - 1 ? 0 : m_end + 1; //如果m_end到达底部，返回到对列顶部
}
int Queue::Pop()
{
	if (m_size <= 0)
		return -1; //队列中没有元素，无法弹出

	m_size--;
	int res = m_start;
	m_start = m_start == m_length - 1 ? 0 : m_start + 1;
	return m_arr[res];
}
int Queue::Peek()
{
	if (m_size <= 0)
		return -1; //队列中没有元素，无法弹出

	return m_arr[m_start];
}


//for test
/*int main()
{
	Stack stack(5);
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
	
	Queue queue(5);
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


	return -1;

}*/