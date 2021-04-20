# Vector in C
My realization vector from c++ in C

### Functions
1. cVectorInit(Vector*, capacity, typeSize)
   * Init new vector structur
   * Params:
      * Vector*: you vector
      * capacity: start vector size, if size = 0 then size = defaultsize (10)
      * typeSize: syze of type which contains in vector
2. cVectorResize(Vector*, newSize)
   * Resize vector
   * Params:
      * Vector*: you vector
      * newSize: new vector size if size < 1 then vector free
3. cVectorAddItem(Vector*, data)
   * Emplace data back vector
   * Params:
      * Vector*: you vector
      * data: data to add vector
4. cVectorGetItem(Vector*, index)
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
     * vector: you vector
     * typeSize: syze of type which contains in vector
2. GET_VECTOR_ITEM(type, vector, index)
   * Get value by type using in vector
   * Params:
     * type: return type
     * vector: you vector
     * index: item index 
3. FREE_VECTOR(vector)
   * Free data in vector and set capacity to 0
   * Params:
     * vector: you vector

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

        a = GET_VECTOR_ITEM(int, vec, 1); 
        // or a = GET_VECTOR_ITEM(typeof(a), vec, 1);

        printf("%i\n", a);

        FREE_VECTOR(vec);

        return 0;
    }
```
