// merge sort

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Strictly saying, merge sort belongs to unit 8 since dynamic memory
// must be used. Merge sort divide the array into two subparts, sort
// each one individually, and merge them to the original array.

// Merge sort:
// 1. Divide the array into two subparts (of equal length). O(n)
// 2. If the length of the array is not 1, repeat step 1. Do this
// for both subparts. 2 * T(n/2)
// 3. Put each pair of arrays together, in sorted order. O(n)
// 4. Repeat for each time the array is divided into subparts. 2 * T(n/2)

// The total time is T(n) = 2 * (O(n) + 2 * T(n/2)) = O(n*log(n))
// merge(dest, src1, len1, src2, len2) modifies dest to contain
//   the elements from both src1 and src2 in sorted order
// requires: length of dest is at least (len1 + len2) [not asserted]
//           src1 and src2 are sorted [not asserted]
// effects: modifies dest
// time: O(n), where n is len1 + len2
void merge(int dest[], const int src1[], int len1,
                       const int src2[], int len2) {
  assert(dest);
  assert(src1);
  assert(src2);
  int pos1 = 0;
  int pos2 = 0;
  for (int i = 0; i < len1 + len2; ++i) {
    if (pos1 == len1 || (pos2 < len2 && src2[pos2] < src1[pos1])) {
      dest[i] = src2[pos2];
      ++pos2;
    } else {
      dest[i] = src1[pos1];
      ++pos1;
    }
  }
}

// merge_sort(a, len) sorts the elements of a in ascending order
// requires: a is a valid array with given len [not asserted]
// effects: modifies a
void merge_sort(int a[], int len) {
  assert(a);
  if (len <= 1) {
    return;
  }
  int llen = len / 2;
  int rlen = len - llen;
  
  int *left = malloc(llen * sizeof(int));
  int *right = malloc(rlen * sizeof(int));
  
  for (int i = 0; i < llen; ++i) {
    left[i] = a[i];
  }
  for (int i = 0; i < rlen; ++i) {
    right[i] = a[i + llen];
  }
  
  merge_sort(left, llen);
  merge_sort(right, rlen);
  
  merge(a, left, llen, right, rlen);
  
  free(left);
  free(right);
}

// array_print(arr, arr_len) prints arr (with a length of arr_len)
// requires: arr_len must be non-negative
// effects: produces output
// time: O(n)
void array_print(const int *arr, const int arr_len) {
    printf("Array contents: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d", arr[i]);
        if (i < arr_len - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
  int a[7] = {8, 6, 7, 5, 3, 0, 9};
  array_print(a, 7);
  merge_sort(a, 7);
  array_print(a, 7);
}