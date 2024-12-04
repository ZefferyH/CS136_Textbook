// while loop, do while loop, for loop, break, continue

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void statement(void){
    // do something
}

int main(void) {
    bool expression = false;
    // while loop:
    while (expression) {
        statement();
    }
    // do while loop:
    do {
        statement();
    } while (expression);
    // break: exit the loop 
    // continue skip this iteration, go to expression immediately

    // for loops:
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i); // prints 0-9
    }
}