// declare, assign, initialize, mutation, constant
#include <assert.h>

// global constant: 
const int global_const = 69;
// global variable:
int global_var = 96;
// do not use global variables, unless it is absolute necessary (very few cases)

int main(void) {
    // This is how a variable is initialized in C
    // declaration:
    int a;
    // assignment:
    a = 1;
    // declaration + assignment = initialization:
    int b = 1;

    // mutation happens in C whenever an identifier's value changed
    int i = 1;
    assert(i == 1);
    i = 2;
    assert(i == 2);
    
    // x+=1 equivalent to x = x + 1
    // same with - * / %
    // x++ is x = x + 1;
    // x-- is x = x - 1;
    // ++x is the same, but not quite:
    int x = 5;
    int j = x++;
    assert(j == 5 && x == 6);
    x = 5;
    j = ++x;
    assert(j == 6 && x == 6);
    // always use bracket to prevent confusion

    // const:
    const int x = 5;
    // constants are not mutable.
}