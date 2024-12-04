// BST, binary search tree

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Tree Terminology:

// -the root node has no parent, all others have exactly one
// -nodes can have multiple children
// -in a binary tree, each node has at most two children
// -a leaf node has no children
// -the height of a tree is the maximum possible number of nodes from the root to a leaf (inclusive)
// -the height of an empty tree is zero
// -the number of nodes is known as the node count

struct bstnode {
  int item;
  struct bstnode *left;
  struct bstnode *right;
  int count;
};

struct bst {
  struct bstnode *root;
};

// see bst.h for documentation
struct bst *bst_create(void) {
  struct bst *t = malloc(sizeof(struct bst));
  t->root = NULL;
  return t;
}

// bstnode_destroy(node) deallocates all dynamically allocated memory
//   within the entire bst
// effects : the memory at node is invalid (freed)
// time : O(n)
static void bstnode_destroy(struct bstnode *node) {
  if (node) {
    bstnode_destroy(node->left);
    bstnode_destroy(node->right);
    free(node);
  }
}

void bst_destroy(struct bst *t) {
  assert(t);
  bstnode_destroy(t->root);
  free(t);
}

// update_count(node) updates the count augmentation
// effects: mutates node->count
static void update_count(struct bstnode *node) {
  if (node) {
    node->count = 1;
    if (node->left) node->count += node->left->count;
    if (node->right) node->count += node->right->count;
  }
}

struct bstnode *new_leaf(int i) {
  struct bstnode *leaf = malloc(sizeof(struct bstnode)); 
  leaf->item = i;
  leaf->count = 1;
  leaf->left = NULL;
  leaf->right = NULL;
  return leaf;
}

void insert_bstnode(int i, struct bstnode *node) {
  assert(node);
  if (i < node->item) {
    if (node->left) {
      insert_bstnode(i, node->left);
    } else {
      node->left = new_leaf(i);
    }
  } else if (i > node->item) {
      if (node->right) {
        insert_bstnode(i, node->right);
    } else {
        node->right = new_leaf(i);
    }
  } // else do nothing, as item already exists
  update_count(node);
}
    
void bst_insert(int i, struct bst *t) {
  assert(t);
  if (t->root) {
    insert_bstnode(i, t->root);
  } else {
    t->root = new_leaf(i);
  }
}

static int select_node(int k, struct bstnode *node) { 
  assert(node);
  assert(0 <= k);
  assert(k < node->count);
  int left_count = 0;
  if (node->left) left_count = node->left->count;
  if (k < left_count) return select_node(k, node->left); 
  if (k == left_count) return node->item;
  return select_node(k - left_count - 1, node->right);
}

int bst_select(int k, struct bst *t) {
  assert(t);
  return select_node(k, t->root);
}

// bstnode_print(node, first) Print the current node. Proceed by a comma
//   if it is not *first, otherwise makes other nodes not *first.
// requires : node and first are not NULL
// effects : prints output, may mutate *first
// time : O(1)
static void bstnode_print(struct bstnode *node, bool *first) {
  assert(node);
  assert(first);
  if (*first) {
    *first = false;
  } else {
    printf(",");
  }
  printf("%d", node->item);
}

// bstnodes_print(node, first) Print the sub-tree rooted at node in
//   in order from smallest to largest. Procced by a comma if not *first, 
//   otherwise updates *first.
// requires : first is not NULL
// effects : prints output, may mutate first
// time : O(n)
static void bstnodes_print(struct bstnode *node, bool *first) { 
  assert(first);
  if (node) {
    bstnodes_print(node->left, first);
    bstnode_print(node, first);
    bstnodes_print(node->right, first);
  }
}

void bst_print (struct bst *t) {
  assert(t);  
  bool first = true;
  printf("[");
  bstnodes_print(t->root, &first);
  printf("]\n");
}

int main() {
  struct bst *t = bst_create();
  bst_insert(40, t);
  bst_insert(20, t);
  bst_insert(50, t);
  bst_insert(10, t);
  bst_print (t);
  printf("%d\n", bst_select(1, t));
  bst_destroy(t);
}

// let n = number of nodes
// let h = height of the tree
// the running time of bst_insert is O(h)
// The definition of a balanced tree is a tree where the height (h) is O(logn)
// Conversely, an unbalanced tree is a tree with a height that is not O(logn)
// The height of an unbalanced tree is O(n).

// For a balanced tree, the runtime of insert, remove, and search are O(logn),
// where as unbalanced tree has runtime O(n)