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

#define which_max(x,y) ((x >= y) ? x : y)

avl_t *createNode(int value) {
    avl_t *node = (avl_t*)malloc(sizeof(avl_t));
    node->data = value;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

avl_t *updateHeight(avl_t *t, int lh, int rh) {
    if (t->left == NULL && t->right == NULL) t->height = 0;
    else if (t->left == NULL) t->height = rh + 1;
    else if (t->right == NULL) t->height = lh + 1;
    else t->height = which_max(lh, rh) + 1;
    return t;
}

avl_t *right_rotation(avl_t *t) {
    avl_t *tmp = t;
    t = t->left;
    tmp->left = t->right;
    t->right = tmp;
    int lh, rh;
    if (tmp->left == NULL) lh = -1;
    else lh = tmp->left->height;
    if (tmp->right == NULL) rh = -1;
    else rh = tmp->right->height;
    tmp = updateHeight(tmp, lh, rh);
    return t;
}

avl_t *left_rotation(avl_t *t) {
    avl_t *tmp = t;
    t = t->right;
    tmp->right = t->left;
    t->left = tmp;
    int lh, rh;
    if (tmp->left == NULL) lh = -1;
    else lh = tmp->left->height;
    if (tmp->right == NULL) rh = -1;
    else rh = tmp->right->height;
    tmp = updateHeight(tmp, lh, rh);
    return t;
}

avl_t *leftRight_rotation(avl_t *t) {
    t->left = left_rotation(t->left);
    t = right_rotation(t);
    return t;
}

avl_t *rightLeft_rotation(avl_t *t) {
    t->right = right_rotation(t->right);
    t = left_rotation(t);
    return t;
}

avl_t *check_balance(avl_t *t, int *lh, int *rh) {
    if (t->left == NULL) *lh = -1;
    else *lh = t->left->height;
    if (t->right == NULL) *rh = -1;
    else *rh = t->right->height;

    if (*lh - *rh > 1) {
        if (t->left->left == NULL) *lh = -1;
        else *lh = t->left->left->height;
        if (t->left->right == NULL) *rh = -1;
        else *rh = t->left->right->height;

        if (*lh > *rh) t = right_rotation(t);
        else t = leftRight_rotation(t);
    }
    else if (*rh - *lh > 1) {
        if (t->right->left == NULL) *lh = -1;
        else *lh = t->right->left->height;
        if (t->right->right == NULL) *rh = -1;
        else *rh = t->right->right->height;

        if (*lh > *rh) t = rightLeft_rotation(t);
        else t = left_rotation(t);
    }
    return t;
}

avl_t *insert(avl_t *t, int value) {
    if (t == NULL) return createNode(value);
    if (value < t->data) t->left = insert(t->left, value);
    else t->right = insert(t->right, value);
    int lh, rh;
    t = check_balance(t, &lh, &rh);
    t = updateHeight(t, lh, rh);
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
    int lh, rh;
    t = check_balance(t, &lh, &rh);
    t = updateHeight(t, lh, rh);
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