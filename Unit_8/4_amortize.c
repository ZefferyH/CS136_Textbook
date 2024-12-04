// amortize analysis

#include <assert.h>
struct stack {
  int len;
  int maxlen;
  int *data;
};

// recall from 3_ADT_revisit:

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
// Imagine if we push n items. Assume max_len starts at 1.
// Then for each time we pushed an item, the time used is
// 1    2    3    4    5    6    7    8    9 ...
// O(n) O(n) O(1) O(n) O(1) O(1) O(1) O(n) O(1)
// notice that the time is O(n) iff n = 2^k for some int k.
// Then on average, the time spend for pushing n items
// is O(n) / n = O(1)
// Note: the above analyzation is very informal. The formal
// definition is beyond the scope of this course. 