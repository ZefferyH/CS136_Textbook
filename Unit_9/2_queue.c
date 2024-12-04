// queue

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// A queue is like a “lineup”, where new items go to the “back” of the line,
// and the items are removed from the “front” of the line. While a stack is LIFO,
// a queue is FIFO (first in, first out).

struct llnode {
  int item;
  struct llnode *next;
};

struct queue {
  struct llnode *front;
  struct llnode *back;    // <--- NEW
};

struct queue *queue_create(void) {
  struct queue *q = malloc(sizeof(struct queue));
  q->front = NULL;
  q->back = NULL;
  return q;
}

void queue_add_back(int i, struct queue *q) {
  assert(q);
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = i;
  newnode->next = NULL;
  if (q->front == NULL) {
    // queue was empty
    q->front = newnode;
  } else {
    q->back->next = newnode;
  }
  q->back = newnode;
}

int queue_remove_front(struct queue *q) {
  assert(q);
  assert(q->front);
  int retval = q->front->item;
  struct llnode *old_front = q->front;
  q->front = q->front->next;
  free(old_front);
  if (q->front == NULL) {
    // queue is now empty
    q->back = NULL;
  }
  return retval;
}

int queue_front(const struct queue *q) {
  assert(q);
  assert(q->front);
  return q->front->item;
}

bool queue_is_empty(const struct queue *q) {
  assert(q);
  return q->front == NULL;
}

void queue_destroy(struct queue *q) {
  assert(q);
  while (!queue_is_empty(q)) {
    queue_remove_front(q);
  }
  free(q);
}

int main() {
  struct queue *q = queue_create();
  queue_add_back(4, q);
  queue_add_back(20, q);
  queue_remove_front(q);
  assert(queue_front(q) == 20);
  assert(!queue_is_empty(q));
  queue_destroy(q);
}