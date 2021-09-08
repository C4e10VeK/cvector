#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H

#include <stdio.h>
#include <stdbool.h>

#define cVectorInit(vector, capacity) (cVectorInit_((BaseVector*)vector, capacity, sizeof(**vector.items)))
#define cVectorResize(vector, size) (cVectorResize_((BaseVector*)vector, size))
#define cVectorPushRange(vector, data) (cVectorPushRange_((BaseVector*)vector, data, (sizeof(data)/sizeof(data[0]))))
#define cVectorPush(vector, ...) (cVectorPushItem_((BaseVector*)vector, __VA_ARGS__))
#define cVectorFree(vector) (cVectorResize_((BaseVector*)vector, 0))

typedef struct BaseVector BaseVector;

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
 * @param typeSize - size of type which contains in vector
 *
 * @return pointer to base vector struct
 */
void cVectorInit_(BaseVector *vector, size_t capacity, size_t typesize);

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
bool cVectorResize_(BaseVector* vector, size_t newSize);

/**
 *
 * @breif emplace data back vector
 * 
 * @param vector - your vector struct
 *
 * @param data - data to add vector
 *
 */
void cVectorPushItem_(BaseVector *vector, void *data);

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
void cVectorPushRange_(BaseVector *vector, void *data, size_t itemCount);

#endif //CVECTOR_CVECTOR_H
