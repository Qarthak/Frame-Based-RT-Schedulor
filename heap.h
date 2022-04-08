void swap(int *x, int *y);

// A class for Min Heap
struct MinHeap
{
	int *arr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heapSize; // Current number of elements in min heap
};

typedef struct MinHeap MinHeap;

//Initialize the heap with capacity
void initMinHeap(MinHeap* heap, int capacity);

// to heapify a subtree with the root at given index
void MinHeapify(MinHeap* heap, int );

// to get the parent of a certain node
int parent(int i) { return (i-1)/2; }

// to get index of left child of node at index i
int left(int i) { return (2*i + 1); }

// to get index of right child of node at index i
int right(int i) { return (2*i + 2); }

// to extract the root which is the minimum element
int extractMin(MinHeap* heap);

// Decreases value of key at index i
void decreaseKey(MinHeap* heap, int i, int newVal);

// Returns the minimum key (key at root) from min heap
int getMin(MinHeap* heap) { return heap->arr[0]; }

// Deletes a key stored at index i
void deleteKey(MinHeap* heap, int i);

// Inserts a new key 'k'
int insertKey(MinHeap* heap, int k);