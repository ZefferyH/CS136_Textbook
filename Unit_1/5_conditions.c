// if, else, ? :, recursion

#include <stdio.h>
#include <stdbool.h>

// basic recursion in c:
// adds from 1 to number
int sum(int number) {
    if (number <= 0) {
        return 0; // base case
    } else {
        return sum(number - 1) + number; // recursive case
    }
}

// control flow:
int control_flow(void) {
    return 0;
    printf("Bye"); // this will not be executed
    
}

int main(void) {

    // if and else:
    if (true) {
        // execute this
    } else if (true) {
        // execute this  
    } else {
        // execute this iff all previous are false
    }

    // Recursion:
    printf("Example 1:\n");
    printf("%d\n", sum(10)); // should print 55

    // ? and :
    printf("Example 2:\n");
    bool q = true;

    q ? printf("1\n") : printf("2\n");

    // is equivalent to 

    if (q) {
        printf("1\n");
    } else {
        printf("2\n");
    }
    // this should execute the later part 
    
    !q ? printf("1\n") : printf("2\n");
    // for exp ? x : y, x gets execute if exp is true, and y if false

    control_flow();
    return 0;
}