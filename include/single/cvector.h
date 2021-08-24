#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#define CVECTOR_INLINE inline __attribute__((always_inline))

#define START_CAPACITY 10

#define VECTOR_INIT(vector, type) cVectorInit(&vector, 10, sizeof(type))
#define VECTOR_ADD_RANGE(vector, data) cVectorAddRange(&vector, data, (sizeof(data)/sizeof(data[0])))
#define VECTOR_GET_ITEM(type, vector, index) (type*)cVectorGetItem(&vector, index)
#define VECTOR_FREE(vector) cVectorResize(&vector, 0)

typedef struct Vector
{
    void* _items;
    size_t _capacity, _typesize, _size;
} Vector;

/**
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
CVECTOR_INLINE void cVectorInit(Vector* vector, size_t capacity, size_t typesize)
{
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->_size = 0;
    vector->_typesize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);
}

/**
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
CVECTOR_INLINE bool cVectorResize(Vector* vector, size_t newSize)
{
    void* pm;

    if (newSize < 1)
    {
        free(vector->_items);
        vector->_capacity = 0;
        vector->_size = 0;

        return true;
    }

    pm = realloc(vector->_items, newSize * vector->_typesize);
    if (pm == NULL) 
    {
        return false;
    }

    vector->_capacity = newSize;   
    vector->_items = pm;

    return true;
}

/**
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
CVECTOR_INLINE void cVectorAddItem(Vector* vector, void* data)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize(vector, vector->_capacity + 5)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typesize, data, vector->_typesize);
    vector->_size++;
}

/**
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
CVECTOR_INLINE void cVectorAddRange(Vector* vector, void* data, size_t itemCount)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize(vector, vector->_capacity + 5)) return;
    }

    if (itemCount >= (vector->_capacity - vector->_size))
    {
        if(!cVectorResize(vector, vector->_capacity + itemCount)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typesize, data, itemCount * vector->_typesize);
    vector->_size += itemCount;
}

/**
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
CVECTOR_INLINE void cVectorSetItemByIndex(Vector* vector, void* data, size_t index)
{
    if (index >= vector->_size) 
    {
        fprintf(stderr, "Index out of range in %s\n", __FUNCTION__);
        exit(1);
    }

    memcpy(vector->_items + index * vector->_typesize, data, vector->_typesize);
}

/**
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
CVECTOR_INLINE void* cVectorGetItem(Vector* vector, size_t index)
{
    if (index >= vector->_capacity) 
    {
        fprintf(stderr, "Index out of range in %s\n", __FUNCTION__);
        exit(1);
    }

    return (vector->_items + index * vector->_typesize);
}

#endif
