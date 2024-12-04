// function pointer

#include <assert.h>

int f(int a, int b) {
    return (a + b);
}

int apply(int (*f)(int, int), int a, int b){
    return f(a,b);
}

int main(void) {
    // defining a function pointer
    // return_type (*pointer_name)(function_input_types,...)
    int (*pt)(int, int) = &f;
    int x = pt(5,3); // we do not need to deference the pointer
    assert(x == 8);
    // we can also pass a function pointer:
    int y = apply(pt, 5, 3);
    assert(y == 8);
}