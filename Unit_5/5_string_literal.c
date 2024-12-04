// string literal

#include <stdio.h>
#include <string.h>
int main(void) {
    // a string literal is a literal string, for example
    char *l = "literal";
    // anything that is within doublequote, and is not part of an array initialization is a string literal.
    // string literal lies in read-only memory, which means they can be consider as constants. 
    // if we tries to modify a literal, it causes undefined behavior.

    /* l will be undefined here
    strcat(l, "abc");
    printf("%s\n", l);
    */


    // arrays vs pointers
    // pointer and array are different. Consider the following case:

    char a[] = "abc"; // array
    char *p = "abc"; // pointer
    char b[] = "cba"; // array
    printf("a == p?: %d\n", strcmp(a,p)); // this is still true (returns 0)
    //a = b;         // INVALID cannot assign an array to a pointer
    a[0] = 'P';    // VALID 
    //p[0] = 'P';    // INVALID (p points at a const literal, cannot be mutated)
    p = b;         // VALID you can assign an address to a pointer
    p[0] = 'D';    // NOW VALID (p points at b)
    printf("a: %s\n", a);
    printf("p: %s\n", p);

} 