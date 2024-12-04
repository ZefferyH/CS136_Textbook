// memory, address, char, overflow

#include <stdio.h>
int main(void) {
    // every variable occupies space in the memory.
    int size = sizeof(int);
    printf("%d\n", size);
    // int has size 4, it can store integers from -(2^32) to 2^32

    // char type
    // char has size 1;
    printf("%d\n", sizeof(char));

    // use single quotes to denote characters:
    char a = 'a';
    a = a + 'A' - 'a';
    printf("%c\n",a);

    // def [overflow] : if we try to represents an int with a value outside of 
    // the int limits, overflow occurs. The value of an int that has overflowed is 
    // undefined. 

    // to_lowercase:
    // c - 'A' + 'a'
    // to_uppercase:
    // c + 'A' - 'a'

    // float: (%f)
    // float can store non integers, but are suseptible to precision errors.
    // a double is a more precise float
    printf("%d\n", sizeof(float)); //4
    printf("%d\n", sizeof(double)); //8
}