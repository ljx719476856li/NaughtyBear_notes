#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
	int GetMidNumber(const vector<int> & vec);

	void HeapSort(vector<int> & vec);
	void HeapInsert(vector<int> & vec, int idx);
	void Heapify(vector<int> & vec, int idx, int heapSize);

private:
	vector<int> m_bigRootHeap;
	vector<int> m_smallRootHeap;

};
int Solution::GetMidNumber(const vector<int> & vec)
{
	if (vec.size() < 2)
		return 0;
	
	for (int i = 0; i < vec.size(); i++)
	{
		m_bigRootHeap.push_back(vec[i]);
		HeapInsert(m_bigRootHeap, i);


	}

}
	
void Solution::HeapSort(vector<int> & vec)
{
	if (vec.size() < 2)
		return;

	for (int i = 0; i < vec.size(); i++)
		HeapInsert(vec, i);

	int size = vec.size();
	swap(vec[0], vec[--size]);
	while (size > 0)
	{
		Heapify(vec, 0, size);
		swap(vec[0], vec[--size]);
	}

}

void Solution::HeapInsert(vector<int> & vec, int idx)
{
	while (vec[idx] < vec[(idx - 1) / 2])
	{
		swap(vec[idx], vec[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void Solution::Heapify(vector<int> & vec, int idx, int heapSize)
{
	int left = idx * 2 + 1;
	while (left < heapSize)
	{
		int smallest = heapSize > left + 1 && vec[left] > vec[left + 1] ? left + 1 : left;
		smallest = vec[idx] > vec[smallest] ? smallest : idx;
		if (smallest == idx)
			break;
		swap(vec[idx], vec[smallest]);
		idx = smallest;
		left = idx * 2 + 1;
	}

}

//int main()
//{
//	vector<int> vec = { 1, 2, 3, 4, 5, 6, 0};
//	Solution sln;
//
//	sln.HeapSort(vec);
//
//	return -1;
//}