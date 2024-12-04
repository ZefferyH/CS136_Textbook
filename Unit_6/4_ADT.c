// ADT

// ADT stands for abstract data type. Usually that means it is 
// a struct of some kind.
// Here are some examples:

// Stack: last in, first out
//  push: adds an item to the top of the stack
//  pop: removes the top item from the stack
//  top: returns the top item on the stack
//  is_empty: determines if the stack is empty

// Queue: first in, first out
//  add_back: adds an item to the end of the queue
//  remove_front: removes the item at the front of the queue
//  front: returns the item at the front
//  is_empty: determines if the queue is empty

// Sequence:
// The sequence ADT is useful when you want to be able to retrieve,
// insert or delete an item at any position in a sequence of items.
//  item_at: returns the item at a given position
//  insert_at: inserts a new item at a given position
//  remove_at: removes an item at a given position
//  length: return the number of items in the sequence

// Set:
// A set is a group of unordered and unindexed items. The set ADT is 
// useful when you want to be able store unique items without worrying
// about their order.
//  add: adds a new item to a set
//  remove: removes an item from a set
//  length: return the number of items in the set
//  member: returns whether or not an item is a member of a set