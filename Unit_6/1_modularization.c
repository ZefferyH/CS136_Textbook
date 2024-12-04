// modularization, function declaration
#include <assert.h>
#include <stdbool.h>
// def [module]: A module provides a collection of 
// functions that share a common aspect or purpose.

// Advantages of modularization:
/*
Re-usability: A good module can be re-used by many clients, so that its easier
to construct larger programs.

Maintainability: It is much easier to test and debug a single module instead of
a large program. If a bug is found, only the module that contains the bug 
needs to be fixed. Or we also can replace a module with an improved version
of it

Abstraction: To use a module, the client needs to understand what functionality 
it provides, but it does not need to understand how it is implemented. This allows 
us to write large programs without having to understand how every piece works.

*/

// if you want to use a external function, this case in fun.c, 
// you need to declare it as such:
bool is_fun(int);

// declare, no definition
int add(int, int);
extern const int funny_number; // in 1_fun.c

int main(void) {
    // usage of is_fun
    assert(is_fun(13));
    assert(!is_fun(3));

    // another thing you can do with function declaration is 
    // write the definition later in the program.
    assert(add(1, 2) == 3);
    // this is ok as long as we define add somewhere in our file

    // the same can also be used for variables. However, we need the extern
    // keyword.
    assert(funny_number == 69); // in 1_fun.c
}

int add(int a, int b) { return a + b; }

// in order to compile this file, you need to link 1_fun.c to this file so that
// it can be used:
// gcc -o 1_modularization 1_modularization.c  1_fun.c