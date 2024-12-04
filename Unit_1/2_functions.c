// function, static type

#include <assert.h>
// a function looks like this:
int add(int a, int b){
    return a + b;
}

// if you forget to use type, c will assume the missing type.
// do not do this:
bad_add(a, b){
    return a + b;
}
int main(void) {
    // def [static type]: all types must be known before the program is run and
    // the type of an identifier cannot change. 

    // do not use integers that starts with 0
    assert(010 == 8);
    // this is true because 010 is evaluated in octal

    // C doesn't allow helper functions inside of another function
}