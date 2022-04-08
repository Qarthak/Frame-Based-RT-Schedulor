#ifndef VECTOR_H
#define VECTOR_H


#define VECTOR_INIT_CAPACITY 4
#define VECTOR_GROWTH_FACTOR 2
#define VECTOR_SHRINK_FACTOR 2
#define VECTOR_SHRINK_THRESHOLD 4
#define INIT_CODE -1
#define SUCCESS_CODE 0

#endif

#ifndef VECTOR_LL_H
#define VECTOR_LL_H

typedef struct vectorLL vectorLL;
struct vectorLL
{
	/*
	 * Pointer to the pointer to the array of elements
	 * The pointer can point to a pointer of any type making this implementation flexible for any type
	*/
	long long* elements;
	
	/*
	 * The total number of elements already stored in the array
	*/
	int totalSize;
	
	/*
	 * The number of elements that can be stored in the allocated space
	*/
	int capacity;
};

/*
 * Function to initialize the vectorLL
*/
vectorLL* vectorLLInit(vectorLL *v);

/*
	* Function to set the element at a particular index in the vectorLL.
	* Returns 0 on success, -1 on failure.
*/
int (vectorLLSet)(vectorLL *v, int index, long long element);

/*
	* Function to get an element from the vectorLL.
	* Returns a pointer to the element on success, NULL on failure.
*/
long long(vectorLLGet)(vectorLL *v, int index);

/*
	* Function to push an element to the end of a vectorLL.
	* Returns 0 on success, -1 on failure.
*/
int (vectorLLPushback)(vectorLL *v, long long element);

/*
	* Function to find size of a vectorLL.
	* Returns size of vectorLL if it's been initialized, -1 if it still points at NULL
*/
int (vectorLLSize)(vectorLL *v);

/*
	* Function to resize the vectorLL.
	* Returns 0 on success, -1 on failure.
*/
int (vectorLLResize)(vectorLL *v, int size);

/*
	* Function to delete an element from the vectorLL.
	* Returns 0 on success, -1 on failure.
*/
int (vectorLLDelete)(vectorLL *v, int index);

/*
	* Function to free the vectorLL.
	* Returns 0 on success, -1 on failure.
*/
int (vectorLLFree)(vectorLL *v);


#endif