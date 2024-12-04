// memory of generic ADT

// The problem with generic ADT is that we don't 
// what type of element is stored it it, which makes freeing 
// it really difficult. If you look back at 3_generic_ADT.c,
// it requires the stack to be empty when it is freed,
// essentially requiring the user to free it. 

// However, we can ask the user to provide a free function,
// see the stack implementation below:

struct stack {
  int len;
  int maxlen;
  void **data;
  void (*free_item)(void *);    // function pointer
};

// client provides free function when stack is created

struct stack *stack_create(void (*free_function)(void *)) { 
  assert(free_function);
  struct stack *s = malloc(sizeof(struct stack));
  s->len = 0;
  s->maxlen = 1;
  s->data = malloc(s->maxlen * sizeof(void *));
  s->free_item = free_function;
  return s;
}

// note: no longer requires stack to be empty
void stack_destroy(struct stack *s) {
  assert(s);
  for (int i = 0; i < s->len; ++i) {      // free all of
  	s->free_item(s->data[i]);             // the items
  }
  free(s->data);
  free(s);
}

// Similarly, we can also let user define an compare function
// to the data type, which allow us to sort without knowing
// what data types are we sorting. The implementation would
// be similar to what is above.