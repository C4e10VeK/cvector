#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#ifdef _MSC_VER
#   define CVECTOR_INLINE static inline
#else
#   define CVECTOR_INLINE static inline __attribute__((always_inline))
#endif

#define START_CAPACITY 10

#define cVectorInit(vector, capacity) (cVectorInit_((BaseVector*)vector, capacity, sizeof(**vector.items)))
#define cVectorResize(vector, size) (cVectorResize_((BaseVector*)vector, size))
#define cVectorPushRange(vector, data) (cVectorPushRange_((BaseVector*)vector, data, (sizeof(data)/sizeof(data[0]))))
#define cVectorPush(vector, ...) (cVectorPushItem_((BaseVector*)vector, __VA_ARGS__))
#define cVectorFree(vector) (cVectorResize_((BaseVector*)vector, 0))

typedef struct
{
    void* _items;
    size_t _capacity, _typeSize, _size;
} BaseVector;

#define Vector(type) \
    struct \
    { \
		type *items; \
		size_t _capacity, _typeSize, _size; \
    }

/**
 *
 * @breif init new vector struct.
 *
 * @param vector - your vector struct
 *
 * @param capacity - start vector size if size = 0 then default size = 10
 *
 * @param typeSize-  size of type which contains in vector
 *
 * @return pointer to base vector struct
 */
CVECTOR_INLINE void cVectorInit_(BaseVector *vector, size_t capacity, size_t typesize)
{
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->_size = 0;
    vector->_typeSize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);
}

/**
 *
 * @breif resize vector
 *
 * @param vector - your vector struct
 *
 * @param newSize - new size for vector
 *
 * @return true if vectar has been resize, else return false
 */
CVECTOR_INLINE bool cVectorResize_(BaseVector *vector, size_t newSize)
{
    void* pm;

    if (newSize < 1)
    {
        free(vector->_items);
        vector->_capacity = 0;
        vector->_size = 0;

        return true;
    }

    pm = realloc(vector->_items, newSize * vector->_typeSize);
    if (pm == NULL) 
    {
        return false;
    }

    vector->_capacity = newSize;   
    vector->_items = pm;

    return true;
}

/**
 *
 * @breif emplace data back vector
 * 
 * @param vector - your vector struct
 *
 * @param data - data to add vector
 *
 */
CVECTOR_INLINE void cVectorPushItem_(BaseVector *vector, void *data)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize_(vector, vector->_capacity + 5)) return;
    }

    memcpy((char *)vector->_items + vector->_size * vector->_typeSize, data, vector->_typeSize);
    vector->_size++;
}

/**
 *
 * @breif emplace array to vector
 * 
 * @param vector - your vector struct
 *
 * @param data - array to add vector
 * 
 * @param itemCount - item count in data
 *
 */
CVECTOR_INLINE void cVectorPushRange_(BaseVector *vector, void *data, size_t itemCount)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize_(vector, vector->_capacity + 5)) return;
    }

    if (itemCount >= (vector->_capacity - vector->_size))
    {
        if(!cVectorResize_(vector, vector->_capacity + itemCount)) return;
    }

    memcpy((char *)vector->_items + vector->_size * vector->_typeSize, data, itemCount * vector->_typeSize);
    vector->_size += itemCount;
}

#endif //CVECTOR_CVECTOR_H

