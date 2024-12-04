// stack

#include "5_stack_ADT.h"

// this is an example of the stack ADT discussed in 4_ADT.c
// see stack.h for documentation

void stack_init(struct stack *s) {
  assert(s);
  s->len = 0;  
  s->maxlen = 100;
}

bool stack_is_empty(const struct stack *s) {
  assert(s);
  return s->len == 0;
}

int stack_top(const struct stack *s) {
  assert(s);
  assert(s->len);
  return s->data[s->len - 1];
}

int stack_pop(struct stack *s) {
  assert(s);
  assert(s->len);
  s->len -= 1;
  return s->data[s->len];
}  

void stack_push(int item, struct stack *s) {
  assert(s);
  if (s->len == s->maxlen) {
    printf("FATAL ERROR: max stack size (%d) exceeded\n", 
           s->maxlen);
    exit(-1);
  }
  s->data[s->len] = item;
  s->len += 1;
}
