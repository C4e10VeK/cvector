# Vector in C
My realization vector from c++ in C

### Functions
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
4. cVectorAddItemByIndex(Vector*, data, index)
   * emplace data in vector by index
   * Params:
     * Vector*: your vector
     * data: data to add vector
     * index: index data in vector
   * error: index out of range
5. cVectorGetItem(Vector*, index)
   * Get data from vector from index
   * Params:
     * Vector*: you vector
     * index: item index in vector
   * return data as void*
   * error: index out of range

### Macros
1. INIT_VECTOR(vector, typeSize)
   * Init new vector by default size
   * Params:
     * vector: your vector
     * typeSize: syze of type which contains in vector
2. GET_VECTOR_ITEM(type, vector, index)
   * Get value by type used in vector
   * Params:
     * type: return type
     * vector: your vector
     * index: item index 
3. FREE_VECTOR(vector)
   * Free data in vector and set capacity to 0
   * Params:
     * vector: your vector

Example:
```c
    #include <stdio.h>
    #include <cvector.h>

    int main()
    {
        Vector vec;
        int a = 56;

        INIT_VECTOR(vec, sizeof(int));

        cVectorAddItem(&vec, &a);
        a = 3;
        cVectorAddItem(&vec, &a);
        cVectorAddItemByIndex(&vec, &a, 2);

        a = GET_VECTOR_ITEM(int, vec, 1); 
        // or a = GET_VECTOR_ITEM(typeof(a), vec, 1);

        printf("%i\n", a);

        FREE_VECTOR(vec);

        return 0;
    }
```
