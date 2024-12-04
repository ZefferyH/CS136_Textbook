// pointer, address

#include <stdio.h>
struct posn
{
    int x;
    int y;
};

// a pointer points at an address.
int main(void) {
    int i = 5;
    int *p = &i; // p points at i
    // pointer can also be pointed towards array, string, char, struct, etc.
    // the * is not part of the variable name. To call the variable, simply use p.
    printf("Address of p: %p\n", p); // prints the address

    // pointer to a pointer
    int **a = &p;
    printf("a points at: %p\n", *a); // points at p
    // (void *) can point at anything
    void *b = &i;
    // void pointers cannot be deferenced:
    // printf("%p\n", b); will cause an error
    // but can still be accessed
    int *c = b;
    printf("the value of c: %d\n", *c); // points at i

    // NULL means the pointer is not pointing at anything.
    printf("Null pointer address: %p\n", NULL); // is the 0 address

    // pointers itself, as well as the value it is pointed at can be mutated.
    int x = 1;
    int *y = &x;
    *y = 2; // change x to 2
    y = NULL; // y points at NULL
    printf("The value of x: %d\n", x);
    printf("y points at: %p\n", y);

    struct posn s = {1,2};
    struct posn *p1 = &s;
    // to access stuff in p1, we can do 
    printf("the value of p1->x is: %d\n", p1->x); // equivalent to (*p1).x

    // multiple pointer can point at the same address.
    i = 1;
    int *d = &i;
    int *e = d;
    *e = 2;
    printf("The value of i is: %d", i); // prints 2
}