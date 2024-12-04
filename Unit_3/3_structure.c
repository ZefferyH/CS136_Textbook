// structure

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// a struct called posn with x and y
struct posn {
    int x;
    int y;
}; // don't forget this ';'

int main(void) {
    //structures are mutable:
    struct posn p = {1,2};
    p.x = 5;
    printf("%d\n", p.x);
    
    // or you can change the entire struct:
    struct posn p1 = {9,9};
    p = p1;
    printf("%d\n", p.x);
    // you cannot do this to mutate 
    // p = {3,7}; causes an error

    struct posn p2 = {}; // both set to 0
    struct posn p3 = {.x=2}; //y is 0
    assert(p2.x == 0);
    assert(p3.y == 0); 
    

    // the size of a struct is larger than all of its fields,
    // for posn, it is at least 4 + 4


}