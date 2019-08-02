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
	int _maxSize;
	int _heapSize;
	T* _heap;

	HeapDatabase()
	{
		_maxSize = MAX_SIZE;
		_heapSize = 8;
		_heap = new T;
	}
	HeapDatabase(int heapSize, const T& heap)
	{
		_maxSize = heapSize;
		_heapSize = 0;
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

};

template<typename T>
class Heap
{
public:
	Heap()
	{
		m_heapDatabase = new HeapDatabase<T>;
		HeapInit(SWAPMODE::MAX);
	}
	Heap(T arr)
	{
		m_heapDatabase->_heap = new HeapDatabase<T>; //调用构造函数
		m_heapDatabase->_heap = arr;
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
};

template<typename T>
void Heap<T>::HeapInit(SWAPMODE smode)
{
	//for (int i = m_heapDatabase->_heapSize / 2; i >= 1; i--)
	//{
	//	m_heapDatabase->_heap[0] = m_heapDatabase->_heap[i];
	//	int son = i * 2;
	//	while (son <= m_heapDatabase->_heapSize)
	//	{
	//		if (son < m_heapDatabase->_heapSize &&
	//			(smode == SWAPMODE.MAX : m_heapDatabase->_heap[son] < m_heapDatabase->_heap[son + 1] ? m_heapDatabase->_heap[son] > m_heapDatabase->_heap[son + 1])
	//			son++;
	//		if (m_heapDatabase->_heap[0] >= m_heapDatabase->_heap[son])
	//			break;
	//		else
	//		{
	//			m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[son];
	//			son *= 2;
	//		}
	//	}
	//	m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[0];
	//}
	if (smode == SWAPMODE::MAX)
	{
		for (int i = m_heapDatabase->_heapSize / 2; i >= 1; i--)
		{
			m_heapDatabase->_heap[0] = m_heapDatabase->_heap[i];
			int son = i * 2;
			while (son <= m_heapDatabase->_heapSize)
			{
				if (son < m_heapDatabase->_heapSize && m_heapDatabase->_heap[son] < m_heapDatabase->_heap[son + 1])
					son++;
				if (m_heapDatabase->_heap[0] >= m_heapDatabase->_heap[son])
					break;
				else
				{
					m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[son];
					son *= 2;
				}
			}
			m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[0];
		}
	}
	else
	{
		for (int i = m_heapDatabase->_heapSize / 2; i >= 1; i--)
		{
			m_heapDatabase->_heap[0] = m_heapDatabase->_heap[i];
			int son = i * 2;
			while (son <= m_heapDatabase->_heapSize)
			{
				if (son < m_heapDatabase->_heapSize && m_heapDatabase->_heap[son] > m_heapDatabase->_heap[son + 1])
					son++;
				if (m_heapDatabase->_heap[0] <= m_heapDatabase->_heap[son])
					break;
				else
				{
					m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[son];
					son *= 2;
				}
			}
			m_heapDatabase->_heap[son / 2] = m_heapDatabase->_heap[0];
		}
	}
}







