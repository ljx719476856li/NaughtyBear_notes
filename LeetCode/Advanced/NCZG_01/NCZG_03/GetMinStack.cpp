#include <iostream>
#include <stack>
using namespace std;

/*
实现一个·特殊的栈，在实现栈的基础功能的基础上，再实现返回栈中的最小元素的操作
*/

class MinStack
{
public:
	void Push(int num);
	int Pop();
	int Peek();
	int GetMin();

private:
	stack<int> statckMin;
	stack<int> statckData;
	
};

void MinStack::Push(int num)
{
	if (statckMin.empty()) //statckMin入栈条件1：stackMin栈长度为0
		statckMin.push(num);
	else if (num <= GetMin())//statckMin入栈条件2：当前入栈元素小于stackMin顶部元素
		statckMin.push(num);

	statckData.push(num); //num必定入栈stackData
}
int MinStack::Pop()
{
	if (statckData.empty())
		return -1;
	int var = statckData.top();
	statckData.pop();

	//特殊条件，出栈元素 == stackMin栈顶的数时，需从stackMin中也出栈
	if (var == GetMin())
		statckMin.pop();

	return var;
}
int MinStack::Peek()
{
	if (statckData.empty())
		return -1;
	int var = statckData.top();

	return var;
}

int MinStack::GetMin()
{
	if (statckMin.empty())
		return -1;

	return statckMin.top();
}

int main()
{
	MinStack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(0);
	int var = stack.Pop();
	int num = stack.GetMin();

	return -1;
}