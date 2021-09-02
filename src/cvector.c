#include <cvector.h>
#include <stdlib.h>
#include <memory.h>

#define START_CAPACITY 10

typedef struct BaseVector
{
    void* _items;
    size_t _capacity, _typeSize, _size;
} BaseVector;

BaseVector *cVectorInit_(size_t capacity, size_t typesize)
{
    BaseVector *vector = calloc(1, sizeof(BaseVector));
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->_size = 0;
    vector->_typeSize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);

    return vector;
}

bool cVectorResize_(BaseVector *vector, size_t newSize)
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

void cVectorPushItem_(BaseVector *vector, void *data)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize_(vector, vector->_capacity + 5)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typeSize, data, vector->_typeSize);
    vector->_size++;
}

void cVectorPushRange_(BaseVector *vector, void *data, size_t itemCount)
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
