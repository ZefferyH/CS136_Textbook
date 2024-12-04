// pointer mutation, returning address

#include <stdio.h>

void inc(int i) {
    ++i;
}
void inc_pt(int *i) {
    ++(*i);
}
int main(void) {
    // consider the following:
    int x = 1;
    inc(x);
    // should x be 2?
    printf("Value of x:%d\n", x); // prints 1

    // when a variable is passed to a function, its value is passed, not the variable itself.
    // What if we pass an address?
    int *y = &x;
    inc_pt(y);
    printf("Value of x new: %d\n", x); // prints 2

    // if a function returns an address, never return an address
    // that is created in its stack
    /* int f(n) {
        return &n; // whatever is stored in this address
                   // disappear after the function returns,
                   // and can cause undefined behavior.
    }
    */
}