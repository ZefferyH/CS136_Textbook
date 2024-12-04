// linear search, binary search

#include <assert.h>
// linear search is quite straight forward, as it iterates
// through the entire array and check if the item is the same
// as the index in the array.

// find(item, a, len) finds the index of item in a,
//   or returns -1 if it does not exist
// requires: len > 0
// time: O(n)
int find(int item, const int a[], int len) {
  assert(a);
  assert(len > 0);
	for (int i = 0; i < len; ++i) {
		if (a[i] == item) {
			return i;
		}
	}
	return -1;
}

// for an array that is sorted, we can implement binary search as
// it is faster than linear search.

// Here's how binary search work:
// 1. Find the array's midpoint. O(1)
// 2. Compare the midpoint to the item. If it is the item,
// stop. O(1)
// 2.1 If it is smaller than the item, go back to step 1,
// with respect to the later half of the array. T(n/2)
// 2.2 If it is larger than the item, go back to step 1,
// with respect to the front half of the array. T(n/2)

// The time of this is:
// T(n) = O(1) + T(n/2) = O(log(n))

// find_sorted(item, a, len) finds the index of item in a,
//   or returns -1 if it does not exist
// requires: a is sorted in ascending order [not asserted]
//           len > 0
// time: O(log n)
int find_sorted(int item, const int a[], int len) {
  assert(a);
  assert(len > 0); 
  int low = 0;
  int high = len - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == item) {
      return mid;
    } else if (a[mid] < item) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main(void) {
    // linear search
    int a[8] = {19, 3, 5, 7, 11, 13, 17, 2};
    assert(find(5, a, 8) == 2);
    assert(find(11, a, 8) == 4);
    assert(find(6, a, 8) == -1);

    // binary search, note that b is sorted
    int b[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    assert(find(2, b, 8) == 0);
    assert(find(11, b, 8) == 4);
    assert(find(18, b, 8) == -1);
}