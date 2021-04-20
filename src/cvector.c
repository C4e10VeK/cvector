#include <cvector.h>
#include <stdlib.h>
#include <memory.h>

#define START_CAPACITY 10

void cVectorInit(Vector *vector, size_t capacity, size_t typesize)
{
    vector->_capacity = capacity;

    if (capacity == 0) vector->_capacity = START_CAPACITY;

    vector->size = 0;
    vector->_typesize = typesize;

    vector->_items = calloc(vector->_capacity, typesize);
}

void cVectorResize(Vector *vector, size_t newSize)
{
    if (newSize < 1)
    {
        free(vector->_items);
        vector->_capacity = 0;
        vector->size = 0;

        return;
    }

    vector->_capacity = newSize;   
    vector->_items = realloc(vector->_items, newSize);
}

void cVectorAddItem(Vector *vector, void *data)
{
    if (vector->size >= vector->_capacity)
    {
        cVectorResize(vector, vector->_capacity + 1);
    }

    memcpy(vector->_items + vector->size * vector->_typesize, data, sizeof(void));
    vector->size++;
}

void* cVectorGetItem(Vector *vector, size_t index)
{
    if (index >= vector->_capacity) 
    {
        fprintf(stderr, "index out of range\n");
        exit(1);
    }

    return (vector->_items + index * vector->_typesize);
}
