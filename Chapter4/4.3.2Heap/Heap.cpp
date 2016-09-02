#include "stdafx.h"
#include "Heap.h"

namespace Heap
{
	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	int* increaseArray(int *src, int&heapN)
	{
		int *pNew = new int[++heapN];
		pNew[heapN - 1] = 0;

		for (int i = 0; i < heapN; ++i)
		{
			pNew[i] = src[i];
		}

		delete src;

		return pNew;
	}

	int* Insert(int* heap, int &heapN, int x)
	{
		heap = increaseArray(heap, heapN);
		heap[heapN - 1] = x;

		int child = heapN - 1;
		int parent = child / 2;

		while (parent >= 0)
		{
			if (heap[child] > heap[parent])
			{
				swap(&heap[child], &heap[parent]);
			}
			else
			{
				return heap;
			}

			child = parent;
			parent = parent / 2;
		}
		return heap;
	}

	void Remove(int* heap, int &heapN)
	{
		if (heapN <= 0)
			return;

		heap[0] = heap[heapN - 1];
		heapN--;

		int parent = 0;
		int child = 1;

		while (child < heapN - 1)
		{
			if (heap[child + 1] > heap[child])
			{
				child = child + 1;
			}
			else
			{
				if (heap[child] > heap[parent])
				{
					swap(&heap[child], &heap[parent]);
				}
				else
				{
					return;
				}
			}

			parent = child;
			child *= 2;
		}
	}
};