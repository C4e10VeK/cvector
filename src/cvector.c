#include <cvector.h>
#include <stdlib.h>
#include <memory.h>

#define START_CAPACITY 10

void cVectorInit(Vector *vector, size_t capacity, size_t typesize)
{
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->_size = 0;
    vector->_typesize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);
}

bool cVectorResize(Vector *vector, size_t newSize)
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

void cVectorAddItem(Vector *vector, void *data)
{
    if (vector->_size >= vector->_capacity)
    {
        if(!cVectorResize(vector, vector->_capacity + 5)) return;
    }

    memcpy(vector->_items + vector->_size * vector->_typesize, data, vector->_typesize);
    vector->_size++;
}

void cVectorAddRange(Vector *vector, void *data, size_t itemCount)
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

void cVectorSetItemByIndex(Vector *vector, void *data, size_t index)
{
    if (index >= vector->_size) 
    {
        fprintf(stderr, "Index out of range in %s\n", __FUNCTION__);
        exit(1);
    }

    memcpy(vector->_items + index * vector->_typesize, data, vector->_typesize);
}

void* cVectorGetItem(Vector *vector, size_t index)
{
    if (index >= vector->_capacity) 
    {
        fprintf(stderr, "Index out of range in %s\n", __FUNCTION__);
        exit(1);
    }

    return (vector->_items + index * vector->_typesize);
}
