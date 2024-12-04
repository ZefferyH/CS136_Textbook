// dynamic memory, malloc, heap, free

#include <stdlib.h>
// stdlib has malloc and free
#include <stdio.h>
#include <assert.h>
// Heap is part of the C memory model, which can be "borrowed" by the program upon
// request. Like any other things borrowed, it also needs to be "returned" after 
// we are done using it.

// Advantages of using heap memory:
// 1. Dynamic: Easy to determine the size of the memory used. 
// 2. Resizable
// 3. Duration: Heap memory last forever until they are freed, unlike 
// stack allocated memory
// 4. Safety: If heap memory overflows, it can be detected easily as opposed to 
// stack overflows. 

struct posn {
  int x;
  int y;
};

// For example 2
// returns an initialized array of length len filled with 1
int *build_array(int len){
    assert(len > 0);
    int *a = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        a[i] = 1;
    }
    return a;
}


int main(void) {
    // malloc(n) allocates memory of n size, and returns
    // an address to that address where the memory is stored.
    // malloc typically use O(1) time, except some rare edge cases.
    // Example 1:
    int *arr = malloc(sizeof(int));
    printf("Example 1:\n    the address of arr is: %p\n", arr);
    printf("    the value of arr[0] is: %d\n", arr[0]);
    // If we only allocate the address of arr, it is uninitialized.

    // when using malloc, always use sizeof with malloc to improve communication.

    // Example 2:
    int *arr2 = build_array(5);
    printf("Example 2:\n    arr2:\n"   );
    for (int i = 0; i < 5; i++) {
        printf("    %d\n", arr2[i]);
    }
    free(arr2); // always free the memory used by malloc, otherwise a memory leak happens

    // What if you requested too much memory?
    int *p = malloc(sizeof(int) * INT_MAX * 999999999);
    assert(p == NULL); // it will return a NULL pointer
    

    // After free() is called upon a pointer, the memory is freed. Any attempt to 
    // access the memory after that is invalid, such as
    // printf("After Free: %d\n", arr2[1]); Address sanitizer will give heap-use-after-free

    // Do not free an address twice, or free an address that is not in heap memory
    // (i.e. created by malloc)
    return 0;
}