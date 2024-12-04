// header file, #include

// header files are also known as interfaces. They provide information to the user about the 
// program that they are using. 
// 1_fun.h is a header file;

#include <assert.h>
#include "1_fun.h"
// #include copy all content of "1_fun.h" and paste it in this file

int main(void) {
    assert(is_fun(69));
}

// in order to compile this file, you need to link 1_fun.c to this file so that
// it can be used:
// gcc -o 2_header 2_header.c  1_fun.c