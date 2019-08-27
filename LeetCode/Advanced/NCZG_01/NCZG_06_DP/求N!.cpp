#include<iostream>
using namespace std;

/*
 题目：求N!
 思路：递归

 推展：求尾随0
*/
class Factorial
{
public:
	long GetFactorial(int num);

};

long Factorial::GetFactorial(int num)
{
	//0!为1
	if (num == 0 || num == 1)
		return 1;


	return num * GetFactorial(num - 1);
}

//int main()
//{
//	Factorial sln;
//	long res = sln.GetFactorial(5);
//
//
//	return 0;
//}