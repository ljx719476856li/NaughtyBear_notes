#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void HeapSort(vector<int>& vec);
	void HeapInsert(vector<int>& vec, int idx);
	void HeapDelete(vector<int>& vec, int idx);
	int HeapPop(vector<int>& vec, int idx);

private:
	void Heapify(vector<int>& vec, int idx, int heapSize);
};

void Solution::HeapSort(vector<int>& vec)
{
	if (vec.size() < 2)
		return;

	for (int i= 0; i < vec.size(); i++)
		HeapInsert(vec, i);

	int size = vec.size();
	swap(vec[0], vec[--size]);
	while (size > 0)
	{
		Heapify(vec, 0, size);
		swap(vec[0], vec[--size]);
	}


}
void Solution::HeapInsert(vector<int>& vec, int idx) //向上处理(大根堆)
{
	while (vec[idx] > vec[(idx - 1) / 2])
	{
		swap(vec[idx], vec[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
void Solution::Heapify(vector<int>& vec, int idx, int heapSize)//向下处理(大根堆)
{
	int left = 2 * idx + 1;
	while (left < heapSize)
	{
		int largest = left + 1 < heapSize && vec[left] < vec[left + 1] ? left + 1 : left;
		largest = vec[idx] < vec[largest] ? largest : idx;
		if (idx == largest)
			break;
		swap(vec[idx], vec[largest]);
		idx = largest;
		left = idx * 2 + 1;
	}
}

void Solution::HeapDelete(vector<int>& vec, int idx)
{
	int size = vec.size();
	if (idx < 0 || idx >= size)
		return;

	vec[idx] = -1;
	swap(vec[idx], vec[--size]);
	for (int i = 0; i < size; i++)
		HeapInsert(vec, i);

	swap(vec[0], vec[--size]);
	while (size > 0)
	{
		Heapify(vec, 0, size);
		swap(vec[0], vec[--size]);
	}

	vec.pop_back();
}

int Solution::HeapPop(vector<int>& vec, int idx)
{
	int size = vec.size();
	if (idx < 0 || idx >= size)
		return - 1;

	int popNum = vec[idx];
	vec[idx] = -1;
	swap(vec[idx], vec[--size]);
	for (int i = 0; i < size; i++)
		HeapInsert(vec, i);

	swap(vec[0], vec[--size]);
	while (size > 0)
	{
		Heapify(vec, 0, size);
		swap(vec[0], vec[--size]);
	}

	vec.pop_back();
	return popNum;
}


//int main()
//{
//	vector<int> vec = { 6, 5, 4, 3, 2, 1 };
//
//	Solution sln;
//	sln.HeapSort(vec);
//	int num = sln.HeapPop(vec, 4);
//	sln.HeapDelete(vec, 0);
//	return -1;
//}