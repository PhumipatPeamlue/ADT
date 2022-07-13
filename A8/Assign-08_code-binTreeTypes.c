#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#include<math.h>

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int is_full(tree_t *t){
  if (t->left != NULL && t->right == NULL){
    return 0;
  }
  if (t->left == NULL && t->right != NULL){
    return 0;
  }
  if (t->left == NULL && t->right == NULL){
    return 1;
  }
  int check_left = is_full(t->left);
  if (check_left == 0){
    return 0;
  }
  int check_right = is_full(t->right);
  if (check_right == 0){
    return 0;
  }
  else{
    return 1;
  }
}

int size(tree_t *t){
  if (t == NULL){
    return 0;
  }
  return size(t->left) + size(t->right) + 1;
}

int height(tree_t *t){
  if (t == NULL){
    return -1;
  }
  int hl = height(t->left);
  int hr = height(t->right);
  if (hl > hr){
    return hl + 1;
  }
  else{
    return hr + 1;
  }
}

int is_perfect(tree_t *t){
  int s = size(t);
  int h = height(t);
  if (s == (int)pow(2,h+1) - 1){
    return 1;
  }
  else{
    return 0;
  }
}

int is_complete(tree_t *t){
  int ht = height(t);
  if (ht == 0){
    return 1;
  }
  else{
    if (ht == 1){
      if (t->left == NULL && t->right != NULL){
        return 0;
      }
      else{
        return 1;
      }
    }
    int pl = is_perfect(t->left);
    int pr = is_perfect(t->right);
    int hl = height(t->left);
    int hr = height(t->right);
    if (pl && pr){
      if (hl - hr == 0 || hl - hr == 1){
        return 1;
      }
      else{
        return 0;
      }
    }
    else if (pr && (hl - hr == 1)){
      return is_complete(t->left);
    }
    else if (pl && (hl == hr)){
      return is_complete(t->right);
    }
    else{
      return 0;
    }
  }
}

int is_degenerate(tree_t *t){
  if (t->left == NULL && t->right == NULL){
    return 1;
  }
  else if (t->left == NULL && t->right != NULL){
    return is_degenerate(t->right);
  }
  else if (t->left != NULL && t->right == NULL){
    return is_degenerate(t->left);
  }
  else{
    return 0; 
  }
}

int is_skewed(tree_t *t){
  int ht = height(t);
  if (ht == 0 || ht == 1){
    return 1;
  }
  else {
    if (t->left == NULL && t->right != NULL){
      if (t->right->right != NULL){
        return is_skewed(t->right);
      }
      else{
        return 0;
    }
    }
    else if (t->left != NULL && t->right == NULL){
      if (t->left->left != NULL){
        return is_skewed(t->left);
      }
      else{
        return 0;
      }
    }
    else{
      return 0;
    }
  }
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for (i=0; i<n; i++) {
      scanf("%d %d %d", &parent, &child, &branch);
      t = attach(t, parent, child, branch);
    }

    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
    return 0;
}
