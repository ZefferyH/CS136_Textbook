// + - * / % round

#include <assert.h>
// assert is a quick way to test your program.
// If the expression inside of assert is false,
// the program is terminated and the rest will not execute

// used for single line comment
/*
    used for multiline comment    
*/
int main(void){
    //add, minus
    assert(1 + 1 == 2);
    assert(2 - 1 == 1);

    //multiply, division
    assert(2 * 3 == 6);
    assert(8 / 4 == 2);

    // modulo 
    assert(9 % 2 == 1);
    // do not use modulo with negative numbers, as
    assert(-3 % 2 == -1);
    assert(3 % -2 == 1);
    // the result might seem unintuitive
    
    // when using /, C rounds towards 0
    assert(1 / 4 == 0);
    assert(3 / 4 == 0);
    assert(-1 / 4 == 0);
    
}