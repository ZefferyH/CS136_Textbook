// pointer arithmetic, array mapping

#include <stdio.h>
#include <assert.h>
/*
let p be a pointer, and i be an integer. 
p + i is equivalent to p + i * sizeof(*p)
p - i is equivalent to p - i * sizeof(*p)
++p is equivalent to p + 1
you can't add two pointers
if p, q are pointers of the same type, then they can be subtracted.
p - q is equivalent to ((p - q) / sizeof(*p))
we can also use <, <=, >, >=, == etc...

*/
// Example: two different way of implementing summing an array

// demonstrating array pointer notation

int sum_array(const int *a, const int len) {
  assert(a);
  assert(len > 0); 
  int sum = 0;
  for (const int *p = a; p < a + len; ++p) {
    sum += *p;
  }
  return sum;
}

// traditional array notation

int sum_array_old(const int a[], const int len) {
  assert(a);
  assert(len > 0); 
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += a[i];
  }
  return sum;
}

int main(void) {
  int my_array[6] = {4, 8, 15, 16, 23, 42};
  printf("sum_array_old: %d\n", sum_array_old(my_array, 6));
  printf("sum_array: %d\n",sum_array(my_array, 6)); 
}

// array mapping:
void array_map(int (*f)(int), int a[], int len) {
  assert(f);
  assert(a);
  assert(len > 0);  
  for (int i = 0; i < len; ++i) {
    a[i] = f(a[i]);
  }
}