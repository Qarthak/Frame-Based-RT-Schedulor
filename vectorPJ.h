#ifndef VECTOR_H
#define VECTOR_H


#define VECTOR_INIT_CAPACITY 4
#define VECTOR_GROWTH_FACTOR 2
#define VECTOR_SHRINK_FACTOR 2
#define VECTOR_SHRINK_THRESHOLD 4
#define INIT_CODE -1
#define SUCCESS_CODE 0

#endif

#ifndef VECTOR_PJ_H
#define VECTOR_PJ_H

struct periodicJob{
	int period;
	float executionTime;
	int relativeDeadline;
	int timesExecuted;
	float remainingExecutionTime;
	int absoluteDeadline;
};
typedef struct periodicJob periodicJob;

typedef struct vectorPJ vectorPJ;
struct vectorPJ
{
	/*
	 * Pointer to the pointer to the array of elements
	 * The pointer can point to a pointer of any type making this implementation flexible for any type
	*/
	periodicJob* elements;
	
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
 * Function to initialize the vectorPJ
*/
vectorPJ* vectorPJInit(vectorPJ *v);

/*
	* Function to set the element at a particular index in the vectorPJ.
	* Returns 0 on success, -1 on failure.
*/
int (vectorPJSet)(vectorPJ *v, int index, periodicJob element);

/*
	* Function to get an element from the vectorPJ.
	* Returns a pointer to the element on success, NULL on failure.
*/
periodicJob* (vectorPJGet)(vectorPJ *v, int index);

/*
	* Function to push an element to the end of a vectorPJ.
	* Returns 0 on success, -1 on failure.
*/
int (vectorPJPushback)(vectorPJ *v, periodicJob element);

/*
	* Function to find size of a vectorPJ.
	* Returns size of vectorPJ if it's been initialized, -1 if it still points at NULL
*/
int (vectorPJSize)(vectorPJ *v);

/*
	* Function to resize the vectorPJ.
	* Returns 0 on success, -1 on failure.
*/
int (vectorPJResize)(vectorPJ *v, int size);

/*
	* Function to delete an element from the vectorPJ.
	* Returns 0 on success, -1 on failure.
*/
int (vectorPJDelete)(vectorPJ *v, int index);

/*
	* Function to free the vectorPJ.
	* Returns 0 on success, -1 on failure.
*/
int (vectorPJFree)(vectorPJ *v);


#endif