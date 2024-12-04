// void pointers

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct posn {
    int x;
    int y;
};

// array_print(arr, arr_len) prints arr (with a length of arr_len)
// requires: arr_len must be non-negative
// effects: produces output
// time: O(n)
void array_print(const int *arr, const int arr_len) {
    printf("Array contents: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d", arr[i]);
        if (i < arr_len - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// For example 3
void swap(int *, int *);
void generic_swap(void *, void *, int);
int main(){
    // a void pointer is 
    void *vp = NULL;
    // unlike any other pointer with a type in front,
    // a void pointer can point at anything. Such as:
    int i = 69;
    vp = &i;
    int *j = vp;
    printf("Example 1:\n");
    printf("j points at: %d\n", *j); // j sucessfully points to 69

    // However, you cannot dereference it directly.
    // printf("%d\n", *vp);

    // an example with struct
    struct posn p = {1, 2};
    vp = &p;
    struct posn *q = vp;
    printf("Example 2:\n");
    printf("q->x:%d\n", q->x); // q->x points at 1
    printf("q->y:%d\n", q->y); // q->y points at 2
    
    // Void pointer are generally dangerous since there 
    // is no way to check if its type is correct. But
    // the reason why we care about void pointer is because
    // it allows us to define genetic functions. Consider 
    // the two functions listed after the main function:

    // Here's an example of how to use generic_swap:
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    generic_swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    int a[3] = {1, 2, 3}, b[] = {-1,-2,-3};
    printf("a before swap:\n");
    array_print(a, 3);
    printf("b before swap:\n");
    array_print(b, 3);
    generic_swap(&a, &b, sizeof(int) * 3);
    printf("a after swap:\n");
    array_print(a, 3);
    printf("b after swap:\n");
    array_print(b, 3);
}
// swaps int
void swap(int *a, int *b) {
  assert(a);
  assert(b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

// swap char, array and anything of the same size
void generic_swap(void *a, void *b, int size) {
    char *p1 = (char *)a; // Cast void pointer to char pointer
    char *p2 = (char *)b; // Cast void pointer to char pointer
    char temp;

    for (int i = 0; i < size; i++) {
        temp = p1[i];    
        p1[i] = p2[i];   
        p2[i] = temp;    
    }
}