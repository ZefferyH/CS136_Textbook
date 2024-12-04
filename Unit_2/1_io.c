// input, output, printf

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// void return: Since we now have print, it is possible that we 
// want a function to return nothing:
void print_something(void) {
    printf("Something");
}


int main(void) {

    printf("Example 1\n");
    // io means input/output. 
    // one simple way to output is printf:
    printf("Hello\n");
    // printf returns the number of character is printed
    assert(printf("Hello\n") == 6);

    printf("Example 2\n");
    // if you want to pass in a variable to printf, you can do it as such:
    char name[] = "name";
    printf("Hello, %s\n", name);
    // %? is the format specifier.
    // %s for string
    // %d for integer
    // %c for character

    // special characters:
    // %% to print %
    // \\ to print backslash
    // \" to print a quote

    printf("Example 3\n");
    print_something();
}