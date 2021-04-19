#include <cvector.h>
#include <stdlib.h>
#include <memory.h>

#define START_CAPACITY 10

void cVectorInit(Vector *vector, size_t capacity, size_t typesize)
{
    vector->capacity = capacity;

    if (capacity == 0) vector->capacity = START_CAPACITY;

    vector->_pos = 0;
    vector->_typesize = typesize;

    vector->_items = calloc(vector->capacity, typesize);
}

void cVectorResize(Vector *vector, size_t newSize)
{
    if (newSize < 1)
    {
        free(vector->_items);
        vector->capacity = 0;
        vector->_pos = 0;

        return;
    }

    vector->capacity = newSize;   
    vector->_items = realloc(vector->_items, newSize);
}

void cVectorAddItem(Vector *vector, void *data)
{
    if (vector->_pos >= vector->capacity)
    {
        cVectorResize(vector, vector->capacity + 1);
    }

    memcpy(vector->_items + vector->_pos * vector->_typesize, data, sizeof(void));
    vector->_pos++;
}

void* cVectorGetItem(Vector *vector, size_t index)
{
    if (index >= vector->capacity) 
    {
        fprintf(stderr, "index out of range\n");
        exit(1);
    }

    return (vector->_items + index * vector->_typesize);
}
