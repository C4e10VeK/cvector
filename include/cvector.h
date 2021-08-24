#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>
#include <stdbool.h>

#define VECTOR_INIT(vector, type) cVectorInit(&vector, 10, sizeof(type))
#define VECTOR_ADD_RANGE(vector, data) cVectorAddRange(&vector, data, (sizeof(data)/sizeof(data[0])));
#define VECTOR_GET_ITEM(type, vector, index) (type*)cVectorGetItem(&vector, index)
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
 * @param vector - your vector struct
 *
 * @param capacity - start vector size if size = 0 then default size = 10
 *
 * @param typeSize-  size of type which contains in vector
 *
 */
void cVectorInit(Vector* vector, size_t capacity, size_t typesize);

/*
 * Function: cVectorResize
 * ---------------------
 *
 * resize vector
 *
 * @param vector - your vector struct
 *
 * @param newSize - new size for vector
 * 
 * @return true if vectar has been resize, else return false
 */
bool cVectorResize(Vector* vector, size_t newSize);

/*
 * Function: cVectorAddItem
 * ---------------------
 *
 * emplace data back vector
 * 
 * @param vector - your vector struct
 *
 * @param data - data to add vector
 *
 */
void cVectorAddItem(Vector* vector, void* data);

/*
 * Function: cVectorAddRange
 * ---------------------
 *
 * emplace array to vector
 * 
 * @param vector - your vector struct
 *
 * @param data - array to add vector
 * 
 * @param itemCount - item count in data
 *
 */
void cVectorAddRange(Vector* vector, void* data, size_t itemCount);

/*
 * Function: cVectorAddItemByIndex
 * ---------------------
 *
 * emplace data in vector by index
 * 
 * @param vector - your vector struct
 *
 * @param data - data to add vector
 * 
 * @param index - index data int vector
 *
 * @exception index out of range
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
 * @param vector - your vector struct
 *
 * @param index - index data in vector
 *
 * @return data in vector as void*
 * 
 * @exception index out of range
 *
 */
void* cVectorGetItem(Vector* vector, size_t index);

#endif
