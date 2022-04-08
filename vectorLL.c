#include "vectorLL.h"
//Both of these are needed to define NULL. Newer versions can make do with either one
#include <stdio.h>
#include <stdlib.h>

vectorLL* vectorLLInit(vectorLL *v)
{
	//Initialize the vectorLL
	v->capacity = VECTOR_INIT_CAPACITY;
	
	v->totalSize = 0;
	v->elements = malloc(sizeof(long long) * v->capacity);
	return v;
}

int vectorLLSet(vectorLL *v, int index, long long element)
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

long long vectorLLGet(vectorLL *v, int index)
{
	long long readData = INIT_CODE;
	if(v)
	{
		if ((index >= 0) && (index < v->totalSize))
		{
			readData = v->elements[index];
		}
	}
	return readData;
}

int vectorLLPushback(vectorLL *v, long long element)
{
	int status = INIT_CODE;
	if(v)
	{
		if (v->capacity == v->totalSize)
		{
			status = vectorLLResize(v, v->capacity * VECTOR_GROWTH_FACTOR);
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

int vectorLLSize(vectorLL *v)
{
	int totalCount = INIT_CODE;
	if(v)
	{
		totalCount = v->totalSize;
	}
	return totalCount;
}

int vectorLLResize(vectorLL *v, int capacity)
{
	int status = INIT_CODE;
	if(v)
	{
		long long* elements = realloc(v->elements, sizeof(long long) * capacity);
		if (elements)
		{
			v->elements = elements;
			v->capacity = capacity;
			status = SUCCESS_CODE;
		}
	}
	return status;
}

int vectorLLDelete(vectorLL *v, int index)
{
	int status = INIT_CODE;
	int i = 0;
	if(v)
	{
		if ((index < 0) || (index >= v->totalSize))
			return status;
		v->elements[index] = 0;
		for (i = index; (i < v->totalSize - 1); ++i)
		{
			v->elements[i] = v->elements[i + 1];
			v->elements[i + 1] = 0;
		}
		v->totalSize--;
		if ((v->totalSize > 0) && ((v->totalSize) == (v->capacity / VECTOR_SHRINK_THRESHOLD)))
		{
			vectorLLResize(v, v->capacity / VECTOR_SHRINK_FACTOR);
		}
		status = SUCCESS_CODE;
	}
	return status;
}

int vectorLLFree(vectorLL *v)
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
