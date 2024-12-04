// generic ADT

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// Since we have void pointers now, our ADT can store
// data of any type. 

// Here's an implementation of a genetic stack

struct stack {
  int len;
  int maxlen;
  void **data;                                               //! (NEW)
};

struct stack *stack_create(void) {
  struct stack *s = malloc(sizeof(struct stack));
  s->len = 0;
  s->maxlen = 1;
  s->data = malloc(s->maxlen * sizeof(void *));              //!
  return s;
}
  
  
// requires: s is empty                                      //!
void stack_destroy(struct stack *s) {
  assert(s);
  assert(stack_is_empty(s));                                 //!
  free(s->data);
  free(s);
}
  
  
bool stack_is_empty(const struct stack *s) {
  assert(s);
  return s->len == 0;
}
  
  
void stack_push(void *item, struct stack *s) {               //!
  assert(item);
  assert(s);
  if (s->len == s->maxlen) {
  	s->maxlen *= 2;
  	s->data = realloc(s->data, s->maxlen * sizeof(void *));  //!
  }
  s->data[s->len] = item;
  s->len += 1;
}
  
   
const void *stack_top(const struct stack *s) {               //!
  assert(s);
  assert(!stack_is_empty(s));
  return s->data[s->len - 1];
}
  
  
void *stack_pop(struct stack *s) {                           //!
  assert(s);
  assert(!stack_is_empty(s));
  s->len -= 1;
  return s->data[s->len];
}