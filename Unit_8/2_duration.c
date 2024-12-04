// duration, dynamic memory side effects, string input output, resizing arrays

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// for example 1
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
    // As dicussed in dynamic_memory.c, one of the advantages of using heap memory
    // is that it can be returned by a function.
    
    int *arr = build_array(10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    // How to resize an array:
    // 1. create a new array
    // 2. copy item from old array to new array
    // 3. free the old array

    // my_array has a length of 100
    int *my_array = malloc(100 * sizeof(int));
    for (int i = 0; i < 100; ++i) {
        my_array[i] = i;
    }
    // what if we need my_array of length 101?
    int *old = my_array;
    my_array = malloc(101 * sizeof(int));
    for (int i = 0; i < 100; ++i) {
        my_array[i] = old[i];
    }
    free(old);
    // done
    free(my_array);

    // or, we can use realloc, which does the same thing.
    // There is a hidden free in realloc to free the old array.

    // realloc(p, newsize) resizes the memory block at p
    //  to be newsize and returns a pointer to the
    //   new location, or NULL if unsuccessful
    // requires: p must be from a previous malloc/realloc
    //   or NULL (then realloc behaves like malloc)
    // effects: the memory at p is invalid (freed)
    // time: O(n), where n is min(newsize, oldsize)

    // if newsize is larger than p, the appended elements are uninitialized.
}