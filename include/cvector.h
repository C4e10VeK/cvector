#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>

#define VECTOR_INIT(vector, type) cVectorInit(&vector, 10, sizeof(type))
#define VECTOR_ADD_RANGE(vector, data) cVectorAddRange(&vector, data, (sizeof(data)/sizeof(data[0])));
#define VECTOR_GET_ITEM(type, vector, index) *(type*)cVectorGetItem(&vector, index)
#define VECTOR_FREE(vector) cVectorResize(&vector, 0)

typedef struct Vector
{
    void* _items;
    size_t _capacity, _typesize, _size;
} Vector;

/*
 * Function: cVectorInit
 * ---------------------
 *
 * init new vector struct
 *
 * p.s. use macro VECTOR_INIT to init vector by default size
 *
 * vector: your vector struct
 *
 * capacity: start vector size if size = 0 then default size = 10
 *
 * typeSize: size of type which contains in vector
 *
 */
void cVectorInit(Vector* vector, size_t capacity, size_t typesize);

/*
 * Function: cVectorResize
 * ---------------------
 *
 * resize vector
 *
 * vector: your vector struct
 *
 * newSize: new size for vector
 *
 */
void cVectorResize(Vector* vector, size_t newSize);

/*
 * Function: cVectorAddItem
 * ---------------------
 *
 * emplace data back vector
 * 
 * vector: your vector struct
 *
 * data: data to add vector
 *
 */
void cVectorAddItem(Vector* vector, void* data);

/*
 * Function: cVectorAddRange
 * ---------------------
 *
 * emplace array to vector
 * 
 * vector: your vector struct
 *
 * data: array to add vector
 * 
 * itemCount: item count in data
 *
 */
void cVectorAddRange(Vector* vector, void* data, size_t itemCount);

/*
 * Function: cVectorAddItemByIndex
 * ---------------------
 *
 * emplace data in vector by index
 * 
 * vector: your vector struct
 *
 * data: data to add vector
 * 
 * index: index data int vector
 *
 * error:
 * index out of range
 *
 */
void cVectorSetItemByIndex(Vector* vector, void* data, size_t index);

/*
 * Function: cVectorGetItem
 * ---------------------
 *
 * get data from vector from index
 *
 * p.s. use macro VECTOR_GET_ITEM to get value by type used in vector
 * 
 * vector: your vector struct
 *
 * index: index data in vector
 *
 * return: data in vector as void*
 * 
 * error:
 * index out of range
 *
 */
void* cVectorGetItem(Vector* vector, size_t index);

#endif
