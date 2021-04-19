#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>

#define INIT_VECTOR(vector, typeSize) cVectorInit(&vector, 10, typeSize)
#define GET_VECTOR_ITEM(vector, var, index) var = *(typeof(var)*)cVectorGetItem(&vector, index)
#define FREE_VECTOR(vector) cVectorResize(&vector, 0)

typedef struct
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
 * vector: you vector struct
 * capacity: start vector size if size = 0 then default size = 10
 * typeSize: size of type when contains in vector
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
 * vector: you vector struct
 * index: index data from vector
 *
 */
void* cVectorGetItem(Vector* vector, size_t index);

#endif
