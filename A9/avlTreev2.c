#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

#define which_max(x,y) ((x>=y) ? x : y)

avl_t *createNode(int v) {
    avl_t *node = (avl_t*)malloc(sizeof(avl_t));
    node->data = v;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

avl_t *updateHeight(avl_t *t) {
    if (t == NULL) return t;

    if (t->left == NULL && t->right == NULL) t->height = 0;
    else if (t->left == NULL) t->height = t->right->height + 1;
    else if (t->right == NULL) t->height = t->left->height + 1;
    else t->height = which_max(t->left->height, t->right->height) + 1;
    return t;
}

avl_t *right_ro(avl_t *t) {
    avl_t *tmp = t;
    t = t->left;
    tmp->left = t->right;
    t->right = tmp;

    t->left = updateHeight(t->left);
    t->right = updateHeight(t->right);
    t = updateHeight(t);
    return t;
}

avl_t *left_ro(avl_t *t) {
    avl_t *tmp = t;
    t = t->right;
    tmp->right = t->left;
    t->left = tmp;

    t->right = updateHeight(t->right);
    t->left = updateHeight(t->left);
    t = updateHeight(t);
    return t;
}

avl_t *leftRight_ro(avl_t *t) {
    t->left = left_ro(t->left);
    t = right_ro(t);
    return t;
}

avl_t *rightLeft_ro(avl_t *t) {
    t->right = right_ro(t->right);
    t = left_ro(t);
    return t;
}

int checkbalance(avl_t *t) {
    int lh = -1, rh = -1;
    if (t->left != NULL) lh = t->left->height;
    if (t->right != NULL) rh = t->right->height;

    if (lh - rh > 1) return 0;
    else if (rh - lh > 1) return 1;
    return -1;
}

avl_t *fixbalance(avl_t *t, int type) {
    int lh = -1, rh = -1;
    if (type == 0) {
        if (t->left->left != NULL) lh = t->left->left->height;
        if (t->left->right != NULL) rh = t->left->right->height;
        
        if (lh > rh) t = right_ro(t);
        else t = leftRight_ro(t);   
    }
    else {
        if (t->right->left != NULL) lh = t->right->left->height;
        if (t->right->right != NULL) rh = t->right->right->height;

        if (rh > lh) t = left_ro(t);
        else t = rightLeft_ro(t);
    }
    return t;
}

avl_t *insert(avl_t *t, int v) {
    if (t == NULL) return createNode(v);
    else if (v < t->data) t->left = insert(t->left, v);
    else t->right = insert(t->right, v);

    int check = checkbalance(t);
    if (check == 0) t = fixbalance(t, 0);
    else if (check == 1) t = fixbalance(t, 1);
    else t = updateHeight(t);
    return t;
}

int find_min(avl_t *t) {
	while (t->left != NULL) t = t->left;
	return t->data;
}

avl_t *delete(avl_t *t, int v) {
    if (t == NULL) return t;
    else if (t->data == v) {
        if (t->left == NULL && t->right == NULL) {
            free(t);
            return NULL;
        }
        else if (t->left == NULL) {
            avl_t *node = t->right;
            free(t);
            return node;
        }
        else if (t->right == NULL) {
            avl_t *node = t->left;
            free(t);
            return node;
        }
        else {
            int value = find_min(t->right);
            t->data = value;
            t->right = delete(t->right,value);
            return t;
        }
    }
    if (v < t->data) t->left = delete(t->left, v);
    else t->right = delete(t->right, v);
    
    int check = checkbalance(t);
    if (check == 0) t = fixbalance(t, 0);
    else if (check == 1) t = fixbalance(t, 1);
    else t = updateHeight(t);
    return t;
}

int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i=0;i<n;i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                print_tree(t);
                break;
        }
    }
    return 0;
}