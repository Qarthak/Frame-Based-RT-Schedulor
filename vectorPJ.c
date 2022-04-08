#include "vectorPJ.h"
//Both of these are needed to define NULL. Newer versions can make do with either one
#include <stdio.h>
#include <stdlib.h>

vectorPJ* vectorPJInit(vectorPJ *v)
{
	//Initialize the vectorPJ
	v->capacity = VECTOR_INIT_CAPACITY;
	
	v->totalSize = 0;
	v->elements = malloc(sizeof(periodicJob) * v->capacity);
	return v;
}

int vectorPJSet(vectorPJ *v, int index, periodicJob element)
{
	int status = INIT_CODE;
	if(v)
	{
		if ((index >= 0) && (index < v->totalSize))
		{
			v->elements[index] = element;
			status = SUCCESS_CODE;
		}
	}
	return status;
}

periodicJob* vectorPJGet(vectorPJ *v, int index)
{
	if(v)
	{
		if ((index >= 0) && (index < v->totalSize))
		{
			return &(v->elements[index]);
		}
	}
	return NULL;
}

int vectorPJPushback(vectorPJ *v, periodicJob element)
{
	int status = INIT_CODE;
	if(v)
	{
		if (v->capacity == v->totalSize)
		{
			status = vectorPJResize(v, v->capacity * VECTOR_GROWTH_FACTOR);
			if(status != INIT_CODE)
			{
				v->elements[v->totalSize++] = element;
			}
		}
		else
		{
			v->elements[v->totalSize++] = element;
			status = SUCCESS_CODE;
		}
	}
	return status;
}

int vectorPJSize(vectorPJ *v)
{
	int totalCount = INIT_CODE;
	if(v)
	{
		totalCount = v->totalSize;
	}
	return totalCount;
}

int vectorPJResize(vectorPJ *v, int capacity)
{
	int status = INIT_CODE;
	if(v)
	{
		periodicJob* elements = realloc(v->elements, sizeof(periodicJob) * capacity);
		if (elements)
		{
			v->elements = elements;
			v->capacity = capacity;
			status = SUCCESS_CODE;
		}
	}
	return status;
}

int vectorPJDelete(vectorPJ *v, int index)
{
	int status = INIT_CODE;
	int i = 0;
	if(v)
	{
		if ((index < 0) || (index >= v->totalSize))
			return status;
		for (i = index; (i < v->totalSize - 1); ++i)
		{
			v->elements[i] = v->elements[i + 1];
		}
		v->totalSize--;
		if ((v->totalSize > 0) && ((v->totalSize) == (v->capacity / VECTOR_SHRINK_THRESHOLD)))
		{
			vectorPJResize(v, v->capacity / VECTOR_SHRINK_FACTOR);
		}
		status = SUCCESS_CODE;
	}
	return status;
}

int vectorPJFree(vectorPJ *v)
{
	int status = INIT_CODE;
	if(v)
	{
		free(v->elements);
		v->elements = NULL;
		status = SUCCESS_CODE;
	}
	return status;
}
