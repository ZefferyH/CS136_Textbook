// scanf, input

#include <stdio.h>

int main(void) {
    // scanf read from stdin, put the value at address &x, and returns
    // 1 if successfully read 1 input
    // 0 if cannot read the input
    // -1 if read EOF 

    int x = 0;
    int retval;
    retval = scanf("%d", &x);
    printf("%d\n", retval);
    
    // \n is the newline character. It forces the rest of the text to\n 
    // be printed on the next line.

    // scanf("%c") reads whitespace
    // scanf("%c ") ignores whitespace
}