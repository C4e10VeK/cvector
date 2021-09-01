#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#define CVECTOR_INLINE inline __attribute__((always_inline))

#define START_CAPACITY 10

#define cVectorInit(type, capacity) (type##Vector)cVectorInit_(capacity, sizeof(type))
#define cVectorPushRange(vector, data) cVectorPushRange_((BaseVector*)vector, data, (sizeof(data)/sizeof(data[0])))
#define cVectorPush(vector, item) (cVectorPushItem_((BaseVector*)vector, &(typeof(*vector->items)){item}))
#define cVectorFree(vector) (cVectorResize_((BaseVector*)vector, 0))

typedef struct
{
    void* _items;
    size_t _capacity, _typeSize, _size;
} BaseVector;

#define Vector(type) \
    typedef struct \
	{ \
		type *items; \
		size_t _capacity, _typeSize, _size; \
	} *type##Vector

/**
 *
 * @breif init new vector struct.
 * p.s. use macro VECTOR_INIT to init vector by default size
 *
 * @param vector - your vector struct
 *
 * @param capacity - start vector size if size = 0 then default size = 10
 *
 * @param typeSize-  size of type which contains in vector
 *
 * @return pointer to base vector struct
 */
CVECTOR_INLINE BaseVector *cVectorInit_(size_t capacity, size_t typesize)
{
    BaseVector *vector = calloc(1, sizeof(BaseVector));
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->_size = 0;
    vector->_typeSize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);

    return vector;
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
CVECTOR_INLINE bool cVectorResize_(BaseVector* vector, size_t newSize)
{
    void* pm;

    if (newSize < 1)
    {
        free(vector->_items);
        vector->_capacity = 0;
        vector->_size = 0;
        free(vector);

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
CVECTOR_INLINE void cVectorPushItem_(BaseVector* vector, void* data)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize_(vector, vector->_capacity + 5)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typeSize, data, vector->_typeSize);
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
CVECTOR_INLINE void cVectorPushRange_(BaseVector* vector, void* data, size_t itemCount)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize_(vector, vector->_capacity + 5)) return;
    }

    if (itemCount >= (vector->_capacity - vector->_size))
    {
        if(!cVectorResize_(vector, vector->_capacity + itemCount)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typeSize, data, itemCount * vector->_typeSize);
    vector->_size += itemCount;
}

#endif //CVECTOR_CVECTOR_H

