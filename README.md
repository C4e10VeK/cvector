# Vector in C
My realization vector from c++ in C

## Example
```c
#include <cvector.h>

typedef struct
{
	float x;
	float y;
} Vec2;

Vector(Vec2); //Vec2Vector

int main()
{
	Vec2Vector test = cVectorInit(Vec2, 2);	
	
	cVectorPush(test, {5.f, 1.f});
	
	printf("Vec2: %f, %f\n", test->items[0].x, test->items[0].y);
	
	cVectorResize(test, 10);
	
	printf("Vec2Vector->_capacity = %lu\n", test->_capacity);
	
    cVectorFree(test);
	
    return 0;
}
```

