#include"heap.h"
#include<stdlib.h>

void initMinHeap(MinHeap* heap ,int capacity)
{
	heap->heapSize = 0;
	heap->capacity = capacity;
	heap->arr = malloc(capacity * sizeof(int));
}

int insertKey(MinHeap* heap, int k)
{
	if (heap->heapSize == heap->capacity)
	{
		return -1;
	}

	heap->heapSize++;
	int i = heap->heapSize - 1;
	heap->arr[i] = k;

	while (i != 0 && heap->arr[parent(i)] > heap->arr[i])
	{
		swap(&heap->arr[i], &heap->arr[parent(i)]);
		i = parent(i);
	}
	return 0;
}

void decreaseKey(MinHeap* heap, int i, int new)
{
	heap->arr[i] = new;
	while (i != 0 && heap->arr[parent(i)] > heap->arr[i])
	{
	swap(&heap->arr[i], &heap->arr[parent(i)]);
	i = parent(i);
	}
}

int extractMin(MinHeap* heap)
{
	if (heap->heapSize <= 0)
		return __INT_MAX__;
	if (heap->heapSize == 1)
	{
		heap->heapSize--;
		return heap->arr[0];
	}

	int root = heap->arr[0];
	heap->arr[0] = heap->arr[heap->heapSize-1];
	heap->heapSize--;
	MinHeapify(heap, 0);

	return root;
}


void deleteKey(MinHeap* heap, int i)
{
	decreaseKey(heap, i, -__INT_MAX__);
	extractMin(heap);
}

void MinHeapify(MinHeap* heap, int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap->heapSize && heap->arr[l] < heap->arr[i])
		smallest = l;
	if (r < heap->heapSize && heap->arr[r] < heap->arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&heap->arr[i], &heap->arr[smallest]);
		MinHeapify(heap, smallest);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}