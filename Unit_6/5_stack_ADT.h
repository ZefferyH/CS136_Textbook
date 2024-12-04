#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
  int len;
  int maxlen;
  int data[100]; // maxmimum amount of integer in the stack
};

// The following applies to all functions:
// requires: s is a valid stack

// stack_init(s) initializes s to be empty
// effects: modifies s
void stack_init(struct stack *s);

// stack_is_empty(s) determines if s is empty
bool stack_is_empty(const struct stack *s);

// stack_top(s) returns the top element on s
// requires: s is not empty
int stack_top(const struct stack *s);

// stack_pop(s) pops and returns the top element on s
// requires: s is not empty
// effects:  modifies s
int stack_pop(struct stack *s);

// stack_push(item, s) pushes item onto stack s
// effects:  modifies s
//           may display output and exit
void stack_push(int item, struct stack *s);
