// linked_list

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct llnode {
  int item;
  struct llnode *next;
};

struct llist {
  struct llnode *front;
};

// list_create() creates a new, empty list
// effects: allocates memory: call list_destroy
struct llist *list_create(void) {
  struct llist *lst = malloc(sizeof(struct llist));
  lst->front = NULL;
  return lst;
}

// add_front(i, lst) adds i to the front of lst
// effects: modifies lst
void add_front(int i, struct llist *lst) {
  assert(lst);
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = i;
  newnode->next = lst->front;
  lst->front = newnode;
}

// list_length(lst) returns the length of lst
int list_length(const struct llist *lst) {
  assert(lst);
  int len = 0;
  struct llnode *node = lst->front;
  while (node) {
    ++len;
    node = node->next;
  }
  return len;
}

// list_destroy destroys lst
// effects: invalidates lst
void list_destroy(struct llist *lst) {
  assert(lst);
  struct llnode *curnode = lst->front;
  struct llnode *nextnode = NULL;
  while (curnode) {
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(lst);
}

void list_print(const struct llist *lst) {
  assert(lst);
  struct llnode *curnode = lst->front;
  if (curnode == NULL) {
    printf("[empty]\n");
    return;
  }
  while (curnode) {
    printf("%d", curnode->item);
    curnode = curnode->next;
    if (curnode) {
      printf("->");
    }
  }
  printf(".\n");
}

// duplicates and returns a copy of oldlist
struct llist *list_dup(const struct llist *oldlist) {
  assert(oldlist);
  struct llist *newlist = list_create();
  if (oldlist->front) {
    add_front(oldlist->front->item, newlist);
    const struct llnode *oldnode = oldlist->front->next;
    struct llnode *newnode = newlist->front;
    while (oldnode) {
      newnode->next = malloc(sizeof(struct llnode));
      newnode = newnode->next;
      newnode->item = oldnode->item;
      newnode->next = NULL;
      oldnode = oldnode->next;
    }
  }
  return newlist;
}

// insert(i, slst) inserts i into sorted list slst
// requires: slst is sorted [not asserted]
// effects:  modifies slst
// time:     O(n), where n is the length of slst
void insert(int i, struct llist *slst) {
  assert(slst);
  if (slst->front == NULL || i < slst->front->item) {
    add_front(i, slst);
  } else {
    // find the node that will be "before" our insert
    struct llnode *before = slst->front;
    while (before->next && i > before->next->item) {
      before = before->next;
    }
    // now do the insert
    struct llnode *newnode = malloc(sizeof(struct llnode));
    newnode->item = i;
    newnode->next = before->next;
    before->next = newnode;
  }
}

// removes and destroys first item
void remove_front(struct llist *lst) {
  assert(lst);
  assert(lst->front);
  struct llnode *old_front = lst->front;
  lst->front = lst->front->next;
  free(old_front);
}

// remove_item(i, lst) removes the first occurrence of i in lst 
//   returns true if an item is successfully removed
bool remove_item(int i, struct llist *lst) {
  assert(lst);
  if (lst->front == NULL) return false;
  if (lst->front->item == i) {
    remove_front(lst);
    return true;
  }
  struct llnode *before = lst->front;
  while (before->next && i != before->next->item) {
    before = before->next;
  }
  if (before->next == NULL) return false;
  struct llnode *old_node = before->next;
  before->next = before->next->next;
  free(old_node);
  return true;
}

// Demonstration of above functions:

int main(void) {
  struct llist *lst = list_create();

  list_print(lst);

  add_front(23, lst);
  add_front(16, lst);
  add_front(8, lst);

  list_print(lst);
  printf("length of the list: %d\n", list_length(lst));

  insert(15, lst);  
  insert(4, lst);
  insert(42, lst);

  list_print(lst);

  struct llist *dup = list_dup(lst);

  list_destroy(lst);  

  remove_front(dup);
  remove_front(dup);
  remove_item(23, dup);

  list_print(dup);

  list_destroy(dup);
}