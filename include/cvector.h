#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>

#define INIT_VECTOR(vector, typeSize) cVectorInit(&vector, 10, typeSize)
#define GET_VECTOR_ITEM(var, vector, index) var = *(typeof(var)*)cVectorGetItem(&vector, index)
#define FREE_VECTOR(vector) cVectorResize(&vector, 0)

typedef struct Vector
{
    void* _items;
    size_t capacity, _pos, _typesize;
} Vector;

/*
 * Function: cVectorInit
 * ---------------------
 *
 * init new vector struct
 *
 * p.s. use macro INIT_VECTOR to init vector by default size
 *
 * vector: you vector struct
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
 * vector: you vector struct
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
 * vector: you vector struct
 *
 * data: data to add vector
 *
 */
void cVectorAddItem(Vector* vector, void* data);

/*
 * Function: cVectorGetItem
 * ---------------------
 *
 * get data from vector from index
 *
 * p.s. use macro GET_VECTOR_ITEM to get value by type using in vector
 * 
 * vector: you vector struct
 *
 * index: index data from vector
 *
 * return: data in vector as void*
 * 
 * error:
 * index out of range
 *
 */
void* cVectorGetItem(Vector* vector, size_t index);

#endif
