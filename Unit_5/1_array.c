// array, array initialization

#include <stdio.h>

void print_array(int arr[], int size)
{
    // prints an array of integers
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    //def [array] :
    // a data structure contains a fixed number of element of the same type.

    // array initialization
    int a[6] = {1, 2, 3, 4, 5, 6};
    int b[5] = {1, 2}; // this is also valid, as you can only initialize part of the arrays.
    // ! if an array is partially initialized, it will throw arbitrary value (usually 0) into unfilled portions
    print_array(b, 5);
    
    // array in memory
    // int a[6] = {1, 2, 3, 4, 5, 6};
    printf("address a:%p\n", a);
    printf("address &a:%p\n", &a);
    printf("address &a[0]:%p\n", &a[0]);
    // these all point to the same memory address. However, a, &a and &a[0] are different. 
    // a = &a[0] => int *, points at the first integer of a
    // &a => int (*)[6], points at an array of 6 integers

    // oversized array
    int c[3] = {1,2,3,4}; // this would cause a compiler warning
    
    // ! since c doesn't keep track of the length of an array, often times you need to keep track of it manually (by passing it as a parameter)
}