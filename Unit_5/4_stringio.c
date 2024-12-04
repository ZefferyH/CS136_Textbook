// string input output

#include <stdio.h>
#include <string.h>
int main(void) {
    // the format specifier for string is %s
    char a[7] = "string";
    printf("a: %s\n", a); // prints a

    // However, when using scanf, we need to be careful as it may cause a buffer overrun.
    char name[16] = {0};
    // int retval = scanf("%15s", name); // good
    // int retval = scanf("%s", name); could cause buffer overrun
    
    // buffer overrun and null terminator:
    char b[5] = "abcde"; // no null terminator
    printf("b: %s\n", b); // this would run until it meets a "\0" in a memory

    char c[3] = "cat";    // NOT properly terminated! it will cause some undefined behavior as below:
    printf("c: %s\n", c);  
    printf("The length of c is: %d\n", strlen(c));

    //scanf example usage with string:
    /*
    while (1) {
        char prompt[] = "What is your name?";
        char name[15] = {0};
        printf("prompt: %s\n", prompt);
            //if (scanf("%s", name) != 1) break; this is dangerous
            if (scanf("%14s", name) != 1) break; // do this instead
        printf("Welcome, %s!\n", name);
    }
    */
    

}