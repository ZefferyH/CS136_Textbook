// efficiency, algorithm, running time

#include <assert.h>
#include <stdio.h>
// def [Algorithm]: is a description of how you would solve a problem.
// An algorithm can solve any question of the same form. For example,
// a sorting algorithm should be able to sort any list.

// def [Time Efficiency]: describes how long would it take to solve
// a problem using a certain algorithm.

// here's an example:
// note that n = len, length of a
int sum_array(const int a[], int len) {
  assert(a);   
  assert(len > 0);
  int sum = 0;          // 1
  int i = 0;            // 1
  while (i < len) {     // n + 1
    sum = sum + a[i];   // 4n recall a[i] => *(a + i)
    i = i + 1;          // 2n
  }
  return sum;
}
// the total run time of this algorithm, would be 7n + 3. However,
// in this case, the elements in a[] does not effect how many operations
// are performed. For other algorithm, this might not be the case. 
// Consider linear_search
int linear_search(int arr[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int data1[] = {1, 2, 3, 4, 5};
    int data2[] = {5, 4, 3, 2, 1};
    int target = 4;

    int index1 = linear_search(data1, 5, target);
    int index2 = linear_search(data2, 5, target);
    printf("Target found at index %d in data1\n", index1);
    printf("Target found at index %d in data2\n", index2);
    // even though we are use data size of both 5, data1 took more time than data2 
    // for the algorithm to run. To solve this, we invented big-O notation.
    return 0;
}
