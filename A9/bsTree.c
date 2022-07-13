#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t bst_t;

bst_t *createNode(int v) {
    bst_t *node = (bst_t*)malloc(sizeof(bst_t));
    node->data = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst_t *insert(bst_t *t, int v) {
    if (t == NULL) return createNode(v);
    if (v < t->data) t->left = insert(t->left, v);
    else t->right = insert(t->right, v);
    return t;
}

int find(bst_t *t, int v) {
	if (t == NULL) return 0;
	if (t->data == v) return 1;
	else if (v < t->data) return find(t->left, v);
	else return find(t->right, v);
}

int find_min(bst_t *t) {
	while (t->left != NULL) t = t->left;
	return t->data;
}

int find_max(bst_t *t) {
	while (t->right != NULL) t = t->right;
	return t->data;
}


bst_t *delete(bst_t *t, int v) {
    if (t == NULL) return t;
    else if (t->data == v) {
        if (t->left == NULL && t->right == NULL) {
            free(t);
            return NULL;
        }
        else if (t->left == NULL) {
            bst_t *node = t->right;
            free(t);
            return node;
        }
        else if (t->right == NULL) {
            bst_t *node = t->left;
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
    return t;
}

int main(void) {
    bst_t *t = NULL;
    int n,i;
    int command, data;

    scanf("%d", &n);
    for (i=0;i<n;i++) {
        scanf("%d",&command);
        switch (command) {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete(t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
}