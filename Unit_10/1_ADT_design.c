/*
There are a lot of data structures in C, but they have their own
benefits and drawbacks.

Data structure comparison: sequenced data
Function	Dynamic Array	Linked List
item_at	    O(1)	        O(n)
search	    O(n)	        O(n)
insert_at	O(n)	        O(n)
insert_frontO(n)	        O(1)
insert_back	O(1)∗	        O(1)†
remove_at	O(n)	        O(n)
remove_frontO(n)	        O(1)
remove_back	O(1)	        O(1)◇ 
∗->amortized †->requires back pointer ◇requires doubly linked list

Data structure comparison: unsequenced (sorted) data
Operation	Sorted Dynamic Array	Sorted Linked List	Unbalanced BST	Self-Balancing BST
search	O(logn)	O(n)	O(n)	O(logn)
insert	O(n)	O(n)	O(n)	O(logn)
remove	O(n)	O(n)	O(n)	O(logn)
select*	O(1)	O(n)	O(n)	O(logn)†
*: select means retriving the kth element from the list
†: requires a count aug

Design decisions:
An array is a good choice if you frequently access elements at specific positions (random access).
A linked list is a good choice for sequenced data if you frequently add and remove elements at the start.
A self-balancing BST is a good choice for unsequenced data if you frequently search for, add and remove items.
A sorted array is a good choice if you rarely add/remove elements, but frequently search for elements and select the data in sorted order.

Typically, the collection ADTs are implemented as follows.
Stack: linked lists or dynamic arrays
Queue: linked lists
Sequence: linked lists or dynamic arrays. Some libraries provide two different ADTs (e.g., a list and a vector) that provide the same interface but have different operation run-times.
Dictionary (and Sets): self-balanced BSTs or hash tables.
*/