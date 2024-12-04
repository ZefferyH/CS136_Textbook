// sorting algorithm, run time

#include <assert.h>
#include <stdio.h>
// sorting algorithms are probably the best way to show how different algorithm
// can give different results

// swaps the value between a and b in O(1) time 
void swap(int *a, int *b) {
  assert(a);
  assert(b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

// selection sort:
// Find the smallest element in the unsorted portion of the list, put it in front
// in sorted order.

// Here's a visualization
// https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/

// selection_sort(a, len) sorts the elements of a
//   in increasing order
// requires: len > 0
// effects: modifies a
// time: O(n^2)
void selection_sort(int a[], int len) {
  assert(a);
  assert(len > 0);
  for (int i = 0; i < len - 1; ++i) {
    int pos = i;
    for (int j = i + 1; j < len; ++j) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    swap(&a[i], &a[pos]);  
  }
}

// insertion sort:
// The list has a sorted portion and unsorted portion.
// The algorithm takes the closest element from the unsorted
// portion of the list, and swap it with the element before it
// until it is in position (i.e. the element before it is smaller) 

// Here's a visualization
// https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/visualize/

// insertion_sort(a, len) sorts the elements of a
//   in increasing order
// requires: len > 0
// effects: modifies a
// time: O(n^2)
void insertion_sort(int a[], int len) {
  assert(a);
  assert(len > 0); 
  for (int i = 1; i < len; ++i) {
    for (int j = i; j > 0 && a[j - 1] > a[j]; --j) {
      swap(&a[j], &a[j - 1]);
    }
  }
}

// Quicksort:
// 1. Select a pivot element, usually the first element. O(1)
// 2. Move all elements larger than the pivot to the back portion,
// leaving the front portion all less than or equal to the pivot. O(n)
// 3. Put the pivot in the right position (right in front of the back portion). O(1)
// 4. Recursively repeat step 1-3 on the front and back portions of the array. T(n-1)

// The time is T(n) = O(n) + T(n-1), which is O(n^2)

// quick_sort_range(a, first, last) sorts the elements of
//   a in the range a[first]..a[last] (inclusive)
//   in ascending order
// requires: a is a valid array in the range first..last [not asserted]
// effects: modifies a
// time: O(n^2)
void quick_sort_range(int a[], int first, int last) {
  assert(a);
  if (last <= first) return;  // length is <= 1
  
  int pivot = a[first];       // first element is the pivot
  int pos = last;             // where to put next larger
  
  for (int i = last; i > first; --i) {
    if (a[i] > pivot) {
      swap(&a[pos], &a[i]);
      --pos;
    }
  }
  swap(&a[first], &a[pos]);   // put pivot in correct place
  quick_sort_range(a, first, pos - 1);
  quick_sort_range(a, pos + 1, last);
}

// quick_sort(a, len) sorts the elements of a in ascending order
// requires: len > 0
// effects: modifies a
void quick_sort(int a[], int len) {
  assert(a);
  assert(len > 0);  
  quick_sort_range(a, 0, len - 1);
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
    int arr1[8] = {2, 6, 7, 5, 4, 8, 1, 3};
    array_print(arr1, 8);
    selection_sort(arr1, 8);
    printf("Selection Sort:\n");
    array_print(arr1, 8);

    int arr2[8] = {2, 6, 7, 5, 4, 8, 1, 3};
    insertion_sort(arr2, 8);
    printf("Insertion Sort:\n");
    array_print(arr1, 8);
    
    int arr3[8] = {2, 6, 7, 5, 4, 8, 1, 3};
    quick_sort(arr3, 8);
    printf("Quick Sort:\n");
    array_print(arr3, 8);
}