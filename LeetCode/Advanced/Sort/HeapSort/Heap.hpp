#pragma once
#include <iostream>

#define  MAX_SIZE 12

enum SWAPMODE
{
	MAX,
	MIN
};

template<typename T>
struct  HeapDatabase //结构体的定义
{
private:
	int _maxSize;
	int _heapSize;

public:
	T _heap;

	HeapDatabase()
	{
		_maxSize = MAX_SIZE;
		_heapSize = 0;
		//_heap = new T;
	}
	HeapDatabase(int len, const T& heap)
	{
		_maxSize = MAX_SIZE;
		_heapSize = len;
		_heap = heap;
	}
	HeapDatabase(const HeapDatabase& heap)
	{
		_maxSize = heap._maxSize;
		_heapSize = heap._heapSize;
		_heap = heap._heap;
	}

	~HeapDatabase()
	{
		_heapSize = 0, _maxSize = 0;
		if (_heap != nullptr)
			delete _heap;
	}

	int GetHeadSize()
	{
		return _heapSize;
	}
};

template<typename T>
class Heap
{
public:
	Heap()
	{
		m_heapDatabase = new HeapDatabase<T>;
		HeapInit(SWAPMODE::MIN);
	}
	Heap(T arr, int len)
	{
		m_heapDatabase = new HeapDatabase<T>(len, arr);
		//m_heapDatabase->_heap = arr;
		HeapInit(SWAPMODE::MIN);
		//heap = new HeapDatabase(heapSize, m_heapDatabase);
	}

	~Heap()
	{
		if (m_heapDatabase != nullptr)
			delete m_heapDatabase;
	}

public:
	HeapDatabase<T>* m_heapDatabase;

	void HeapInit(SWAPMODE smode);

private:
	void MaxHeapify(int start, int end);
	void MinHeapify(int start, int end);
};

template<typename T>
void Heap<T>::MinHeapify(int start, int end)
{
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {//若子节点指标在范围内才做比较
		if (son + 1 <= end && m_heapDatabase->_heap[son] > m_heapDatabase->_heap[son + 1]) //先比较两个子节点大小，选择最小的
			son++;
		if (m_heapDatabase->_heap[dad] < m_heapDatabase->_heap[son]) //如果父节点小于子节点代表调整完毕，直接跳出函数
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			std::swap(m_heapDatabase->_heap[dad], m_heapDatabase->_heap[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
template<typename T>
void Heap<T>::MaxHeapify(int start, int end)
{
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子节点指标在范围内才做比较
		if (son + 1 <= end && m_heapDatabase->_heap[son] < m_heapDatabase->_heap[son + 1]) //先比较两个子节点大小，选择最大的
			son++;
		if (m_heapDatabase->_heap[dad] > m_heapDatabase->_heap[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
			return;
		else { //否则交换父子内容再继续子节点和孙节点比较
			std::swap(m_heapDatabase->_heap[dad], m_heapDatabase->_heap[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

template<typename T>
void Heap<T>::HeapInit(SWAPMODE smode)
{
	int len = m_heapDatabase->GetHeadSize();
	//初始化 i从最后一个父节点开始调整
	for (int i = len / 2 - 1; i >= 0; i--)
		( smode == SWAPMODE::MAX ? MaxHeapify(i, len - 1) : MinHeapify(i, len - 1) );
		/*MaxHeapify(i, len - 1);*/
	//先将第一个元素和已经排好的元素前一位做交换，再从新调整（刚调整的元素之前的元素），直到排序完毕
		for (int i = len - 1; i > 0; i--) {
			std::swap(m_heapDatabase->_heap[0], m_heapDatabase->_heap[i]);
			( smode == SWAPMODE::MAX ? MaxHeapify(0, i - 1) : MinHeapify(0, i - 1) );
			/*MaxHeapify(0, i - 1);*/
		}

}







