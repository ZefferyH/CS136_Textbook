// ADT, stack

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// note that in module 6, our implementation of stack
// requires the user to define a struct ADT themselves,
// and then call stack_init to fill its starting fields.
// That is because we have no way to allocate memory 
// for out stack ADT via a function. Now we have malloc,
// hence we can improve out implementation:

struct stack {
  int len;
  int maxlen;
  int *data;
};

struct stack *create_stack(void) {
  struct stack *s = malloc(sizeof(struct stack));
  s->len = 0;
  s->maxlen = 1;
  s->data = malloc(s->maxlen * sizeof(int));
  return s;
}

// Time: O(1) Amortized. See 4_amortize.c
void stack_push(int item, struct stack *s) {
  assert(s);
  if (s->len == s->maxlen) {
    s->maxlen *= 2;
    s->data = realloc(s->data, s->maxlen * sizeof(int));
  }
  s->data[s->len] = item;
  s->len += 1;
}

void stack_destroy(struct stack *s) {
  assert(s);
  free(s->data);
  free(s);
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

// this is a demo program for a stack.
//   It reads in integers and then prints them
//   out in reversed order. (last in first out)

int main(void) {
  struct stack *s = create_stack();
  
  while (1) {
    int n = 0;
    if (scanf("%d", &n) != 1) break;
    stack_push(n, s);
  }
  
  while (!stack_is_empty(s)) {
    printf("%d\n", stack_pop(s));
  }
  
  stack_destroy(s);
}