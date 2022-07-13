#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int f;  //frequency
    char word[16];
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap {
    int last_index;
    node_t **data;
} heap_t;

heap_t *init_heap(heap_t *h, int n) {
    h = (heap_t*)malloc(sizeof(heap_t));
    h->last_index = 1;
    h->data = (node_t**)malloc(sizeof(node_t*)*(n+1));
    return h;
}

node_t *createNode() {
    node_t *n = (node_t*)malloc(sizeof(node_t));
    scanf("%s %d", n->word, &n->f);
    n->left = NULL;
    n->right = NULL;
    return n;
}

void swap(node_t **a, node_t **b) {
    node_t *tmp = *a;
    *a = *b;
    *b = tmp;
}

void percolate_up(heap_t *h, int i) {
    if (i <= 1) return;
    if (h->data[i]->f >= h->data[i/2]->f) return;
    swap(&h->data[i], &h->data[i/2]);
    percolate_up(h, i/2);
}

void insert(heap_t *h, node_t *n) {
    h->data[h->last_index] = n;
    if (h->last_index >= 2) percolate_up(h, h->last_index);
    h->last_index++;
}

void percolate_down(heap_t *h, int i) {
    if (2*i >= h->last_index && 2*i+1 >= h->last_index) return;
    node_t *p = h->data[i]; // parent node
    node_t *cl = h->data[2*i]; // child_left node
    node_t *cr = h->data[2*i+1]; // child_right node
    if (p->f <= cl->f && p->f <= cr->f) return;
    else if (p->f > cl->f && p->f > cr->f) {
        if (cr->f < cl->f) {
            swap(&h->data[i], &h->data[2*i+1]);
            percolate_down(h, 2*i+1);
        }
        else {
            swap(&h->data[i], &h->data[2*i]);
            percolate_down(h, 2*i);
        }
    }
    else {
        if (p->f > cl->f) {
            swap(&h->data[i], &h->data[2*i]);
            percolate_down(h, 2*i);
        }
        else {
            swap(&h->data[i], &h->data[2*i+1]);
            percolate_down(h, 2*i+1);
        }
    } 
}

node_t *delete_min(heap_t *h) {
    h->last_index--;
    node_t *del = h->data[1];
    h->data[1] = h->data[h->last_index];
    percolate_down(h, 1);
    return del;
}

node_t *createNode2(heap_t *h) {
    node_t *n = (node_t*)malloc(sizeof(node_t));
    n->left = delete_min(h);
    n->right = delete_min(h);
    n->f = n->left->f + n->right->f;
    return n;
}

void build_treeCode(heap_t *h) {
    if (h->last_index == 2) return;
    node_t *n = createNode2(h);
    insert(h, n);
    build_treeCode(h);
}

void dfs(node_t *n, int *arr, int i) {
    if (n->left == NULL & n->right == NULL) {
        printf("%s: ", n->word);
        int j;
        for (j=0; j<i; j++) {
            printf("%d", *(arr + j));
        }
        printf("\n");
        return;
    }
    *(arr + i) = 0;
    dfs(n->left, arr, i+1);
    *(arr + i) = 1;
    dfs(n->right, arr, i+1);
}

void generateCode(heap_t *h) {
    int code[100];
    dfs(h->data[1], code, 0);
}

int main() {
    heap_t *h = NULL;
    node_t *node = NULL;
    int n, i;

    scanf("%d", &n);
    h = init_heap(h, n);
    for (i=0; i<n; i++) {
        node = createNode();
        insert(h, node);
    }
    build_treeCode(h);
    generateCode(h);
    return 0;
}