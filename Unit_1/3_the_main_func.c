// printf, function ordering, main function

#include <stdio.h>
// stdio includes functions like printf and scanf, 
// input or output
#include <assert.h>

int main(void) {
    // every c program must have one and only one main function.
    // main has no parameter and returns to OS
    // main should always returns int

    // printf:
    printf("Hello World!");
    f();
}

// function ordering:
// this will cause an error:

int f(void){
    return 0;
}

// because it is declared after main
