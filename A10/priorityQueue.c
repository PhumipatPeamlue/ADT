#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m) {
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->last_index = 1;
    h->data = (int*)malloc(sizeof(int) * (m+1));
    return h;
}

void swap(int **a, int **b) {
    int tmp = **a;
    **a = **b;
    **b = tmp;
}

// percolate_upV1
// void percolate_up(heap_t *h, int i) {
//     int *child = h->data + i;
//     while (i > 1) {
//         int *parent = h->data + i/2;
//         if (*parent > *child) break;
//         else swap(&parent, &child);
//         child = parent;
//         i = i/2;
//     }
// }

// percolate_upV2
void percolate_up(heap_t *h, int i) {
    if (i <= 1) return;
    int *child = h->data + i;
    int *parent = h->data + i/2;
    if (*parent > *child) return;
    swap(&parent, &child);
    percolate_up(h, i/2);
}

//percolate_downV1
// void percolate_down(heap_t *h, int i) {
//     int *parent = h->data + i;
//     int *child_left = h->data + 2*i;
//     int *child_right = h->data + (2*i+1);
//     while (i < h->last_index) {
//         if (*parent >= *child_left && *parent >= *child_right) break;
//         if (*parent < *child_left && *parent < *child_right) {
//             if (*child_left > *child_right) {
//                 swap(&parent, &child_left);
//                 i = 2*i;
//             }
//             else {
//                 swap(&parent, &child_right);
//                 i = 2*i+1;
//             }
//         }
//         else if (*child_left > *parent) {
//             swap(&parent, &child_left);
//             i = 2*i;
//         }
//         else if (*child_right > *parent) {
//             swap(&parent, &child_right);
//             i = 2*i+1;
//         }
//     }
// }

//percolate_downV2
void percolate_down(heap_t *h, int i) {
    if (i >= h->last_index) return;
    int *parent = h->data + i;
    int *child_left = h->data + 2*i;
    int *child_right = h->data +(2*i+1);
    if (*parent >= *child_left && *parent >= *child_right) return;
    else if (*parent < *child_left && *parent < *child_right) {
        if (*child_left > *child_right) {
            swap(&parent, &child_left);
            percolate_down(h, 2*i);
        }
        else {
            swap(&parent, &child_right);
            percolate_down(h, 2*i+1);
        }
    }
    else if (*child_left > *parent) {
        swap(&parent, &child_left);
        percolate_down(h, 2*i);
    }
    else {
        swap(&parent, &child_right);
        percolate_down(h, 2*i+1);
    }
}

void insert(heap_t *h, int v) {
    *(h->data + h->last_index) = v;
    if (h->last_index/2 >= 1) percolate_up(h, h->last_index);
    h->last_index++;
}

void delete_max(heap_t *h) {
    if (h->last_index > 1) {
        h->last_index--;
        *(h->data + 1) = *(h->data + h->last_index);
        *(h->data + h->last_index) = 0;
        percolate_down(h, 1);
    }
}

int find_max(heap_t *h) {
    if (h->last_index == 1) return -1;
    return *(h->data + 1);
}

void update_key(heap_t *h, int old, int new) {
    int i = 1;
    while (*(h->data + i) != old) i++;
    *(h->data + i) = new;
    if (*(h->data + i) > *(h->data + i/2)) percolate_up(h, i);
    else if (*(h->data +i) < *(h->data + 2*i)) percolate_down(h, i);
    else if (*(h->data +i) < *(h->data + 2*i+1)) percolate_down(h, i);
}

void bfs(heap_t *h) {
    int i;
    for (i = 1; i < h->last_index ; i++) {
        printf("%d ",*(h->data + i));
    }
    printf("\n");
}

int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0;i<n;i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}