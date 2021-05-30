# Vector in C
My realization vector from c++ in C

## Example
```c
    #include <stdio.h>
    #include <cvector.h>

    int main()
    {
        Vector vec;
        int* b = NULL;
        int a = 56;
        int z[] = {0, 56, 10};

        VECTOR_INIT(vec, int);

        cVectorAddItem(&vec, &a);
        
        a = 3;
        cVectorAddItem(&vec, &a);
        cVectorSetItemByIndex(&vec, &a, 1);

        VECTOR_ADD_RANGE(vec, z);

        b = VECTOR_GET_ITEM(int, vec, 3);

        printf("%i\n", *b);

        VECTOR_FREE(vec);

        return 0;
    }
```

## Functions
1. cVectorInit(Vector*, capacity, typeSize)
   * Init new vector structur
   * Params:
      * Vector*: your vector
      * capacity: start vector size, if size = 0 then size = defaultsize (10)
      * typeSize: syze of type which contains in vector
2. cVectorResize(Vector*, newSize)
   * Resize vector
   * Params:
      * Vector*: your vector
      * newSize: new vector size if size < 1 then vector free
3. cVectorAddItem(Vector*, data)
   * Emplace data back vector
   * Params:
      * Vector*: your vector
      * data: data to add vector
4. cVectorAddRange(Vector*, data, itemCount)
   * Emplace array to vector
   * Params:
     * Vector*: your vector
     * data: array to add vector
     * itemCount: item count in data
5. cVectorAddItemByIndex(Vector*, data, index)
   * emplace data in vector by index
   * Params:
     * Vector*: your vector
     * data: data to add vector
     * index: index data in vector
   * error: index out of range
6. cVectorGetItem(Vector*, index)
   * Get data from vector from index
   * Params:
     * Vector*: you vector
     * index: item index in vector
   * return data as void*
   * error: index out of range

## Macros
1. VECTOR_INIT(vector, type)
   * Init new vector by default size
   * Params:
     * vector: your vector
     * type: type which contains in vector
2. VECTOR_ADD_RANGE(vector, data)
   * Add array in vector
   * params:
     * vector: your vector
     * data: array which adding in vector
3. VECTOR_GET_ITEM(type, vector, index)
   * Get value by type used in vector
   * Params:
     * type: return type
     * vector: your vector
     * index: item index 
4. VECTOR_FREE(vector)
   * Free data in vector and set capacity to 0
   * Params:
     * vector: your vector
