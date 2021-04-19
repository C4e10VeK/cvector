#ifndef CVOXEL_CVOXEL_H
#define CVOXEL_CVOXEL_H

#include <stdio.h>

#define INIT_VECTOR(vector, typeSize) cVectorInit(&vector, 10, typeSize)

typedef struct
{
    void* _items;
    size_t capacity, _pos, _typesize;
} Vector;

void cVectorInit(Vector* vector, size_t capacity, size_t typesize);

void cVectorResize(Vector* vector, size_t newSize);

void cVectorAddItem(Vector* vector, void* data);
void* cVectorGetItem(Vector* vector, size_t index);

int cVectorGetItemInt(Vector* vector, size_t index);

void cVectorFree(Vector* vector);

#endif
