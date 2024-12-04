// assert, ==, !, &&, ||, short circuiting

#include <assert.h>
#include <stdbool.h>
// stdbool allows you to use true and false.

int main(void) {
    // 0 is false, every other int is true.
    assert(1);
    assert(-10123);
    assert(!0);
    // == for equality
    // != for not equal
    // > < >= <= for comparison
    assert(1 == 1);
    assert(1 != 0);
    assert(1 > 0);
    assert(0 < 1);
    
    // && is and; || is or
    // ! is not
    assert(true || false);
    assert(true && true);
    assert(!false);
    // true and false are in <stdbool.h>
    // true is always 1
    assert(true == 1);
    assert(false == 0);

    // short circuiting: C stops evaluating or if there is a true,
    // and stops evaluating and if there is a false.
    assert(1 || (1 / 0));
    assert(!(0 && (1 / 0)));
    // both do not generate an error
}