# Vector in C
My realization vector from c++ in C

## Example
```c
    #include <cvector.h>

	Vector(int); // intVector
	Vector(float); // floatVector

	int main()
	{
    	intVector test = cVectorInit(int, 0);
    	floatVector test2 = cVectorInit(float, 2);
    	cVectorPush(test, 6);
    	cVectorPush(test2, 6.f);

    	printf("Test: %d\n", test->items[0]);
    	printf("Test: %f\n", test2->items[0]);

    	int a = 10;

    	cVectorFree(test);

    	return 0;
	}
```

