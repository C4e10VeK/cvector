# Vector in C
My realization vector from c++ in C

## Example
```c
#include <stdio.h>
#include <cvector.h>

typedef struct
{
    float x;
    float y;
} Vec2;

typedef Vector(Vec2) Vec2Vector;

int main()
{
    Vec2Vector vectors;
    cVectorInit(&vectors, 1);
    Vec2 vector2D = {1.0f, 2.0f};

    cVectorPush(&vectors, &(Vec2){5.f, 5.f});
    cVectorPush(&vectors, &vector2D);

    for (size_t i = 0; i < vectors._size; i++)
        printf("Vec2: %f, %f\n", vectors.items[i].x, vectors.items[i].y);

    cVectorResize(&vectors, 10);

    printf("Vec2Vector->_capacity = %lu\n", vectors._capacity);

    cVectorFree(&vectors);

    return 0;
}

```

