// iterative analysis, recursive analaysis

// What is the runtime of this:
int max(int a, int b) { // O(1) + O(1)
  if (a > b) return a; // O(1) + O(1) 
  return b; // O(1)
}
// Since there is only a fixed amount of O(1),
// this is O(1)
void loop(int n){
    for (int i = 1; i <= n; ++i) { // this loop is executed n times
        max(1, n); // O(1)
    }
}
// since O(n) * O(1) = O(n), this has O(n) time

void double_loop(int n){
    for (int i = 0; i < n; ++i){ // n times
        for (int j = 0; j < n; ++j){ // n times
            max(1, j);
        }
        max(1, i);
    }
}
// since O(n) * O(n) = O(n^2), this has O(n^2) time

// Recursion:
//T(n)=O(1)+T(n−k1)	        =O(n)
//T(n)=O(n)+T(n−k1)	        =O(n^2)
//T(n)=O(n^2)+T(n−k1)	    =O(n^3)
//T(n)=O(1)+T(n/k2)	        =O(logn)
//T(n)=O(1)+k2∗T(n/k2)	    =O(n)
//T(n)=O(n)+k2∗T(n/k2)	    =O(nlogn)
//T(n)=O(1)+T(n−k1)+T(n−k′1)=O(2^n)
// these k denote how many branches is created by each iteration
// all string functions are O(n), with the execption of strcat being O(n+m)