// scope

#include <stdio.h>
// In C, variable are restricted to its scope. 
// Here's an example:

const int i = 69; // checkpoint 1 value

int scope(void){
    printf("Checkpoint 1: %d\n",i);

    int i = 0; // checkpoint 2 value
    printf("Checkpoint 2: %d\n",i);

    i = 1; // mutation; checkpoint 3,6 value
    printf("Checkpoint 3: %d\n",i);
    {
        // in this new scope, we can define a new y:
        int i = 10; // checkpoint 4, 5 value
        printf("Checkpoint 4: %d\n",i);
        {
            // the variable used is always the "closest one" in scope
            printf("Checkpoint 5: %d\n",i);
        }
    }
    // int i = 10 is not in scope, so we go back to i = 1;
    printf("Checkpoint 6: %d\n",i);
}

int main(){
    scope();
}