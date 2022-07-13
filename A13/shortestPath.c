#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vertex {
    int num;
    int weight;
    struct vertex *next;
} vertex_t;

vertex_t *createVertex(int num, int w) {
    vertex_t *vertex = malloc(sizeof(vertex_t));
    vertex->num = num;
    vertex->weight = w;
    vertex->next = NULL;
    return vertex;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(vertex_t **list, int N) {
    vertex_t *tmp_v = list[N];
        while (tmp_v->next != NULL && tmp_v->weight > tmp_v->next->weight) {
            swap(&tmp_v->weight, &tmp_v->next->weight);
            swap(&tmp_v->num, &tmp_v->next->num);
            tmp_v = tmp_v->next;
        }
}

void append(vertex_t **list, int num1, int num2, int w) {
    int tmp_w, tmp_num;
    
    vertex_t *vertex1 = createVertex(num1, w);
    if (list[num2] == NULL || vertex1->weight <= list[num2]->weight) {
        vertex1->next = list[num2];
        list[num2] = vertex1;
    }
    else {
        vertex1->next = list[num2];
        list[num2] = vertex1;
        bubblesort(list, num2);
    }

    vertex_t *vertex2 = createVertex(num2, w);
    if (list[num1] == NULL || vertex2->weight <= list[num1]->weight) {
        vertex2->next = list[num1];
        list[num1] = vertex2;
    }
    else {
        vertex2->next = list[num1];
        list[num1] = vertex2;
        bubblesort(list, num1);
    } 
}

typedef struct node {
    int num;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *back;
} queue_t;

node_t *createNode(int num) {
    node_t *node = malloc(sizeof(node_t));
    node->num = num;
    node->next = NULL;
    return node;
}

queue_t enqueue(queue_t q, int num) {
    node_t *node = createNode(num);
    node->next = q.back;
    q.back = node;
    if (q.front == NULL) q.front = node;

    return q;
}

queue_t dequeue(queue_t q) {
    node_t *del = q.front;
    if (q.front == q.back) {
        q.front = NULL;
        q.back = NULL;
    }
    else {
        node_t *tmp_back = q.back;
        while (tmp_back->next != q.front) {
            tmp_back = tmp_back->next;
        }
        tmp_back->next = NULL;
        q.front = tmp_back;
    }
    free(del);
    return q;
}

void bfs(vertex_t **list, int s, int t, int n) {
    queue_t q = {NULL, NULL};
    q = enqueue(q, s);
    int *dist = malloc(sizeof(int)*n);
    bool *visited = malloc(sizeof(bool)*n);
    int i;
    for (i=0; i<n; i++) {
        dist[i] = -1;
        visited[i] = false;
    }
    dist[s] = 0;
    visited[s] = true;
    
    while (q.front != NULL && q.back != NULL) {
        int row = q.front->num;
        q = dequeue(q);
        
        vertex_t *tmp = list[row];
        while (tmp != NULL) {
            if (visited[tmp->num] == false) {
                dist[tmp->num] = dist[row] + tmp->weight;
                visited[tmp->num] = true;
                if (tmp->num != t) q = enqueue(q, tmp->num);
            }
            else {
                if (dist[row] + tmp->weight < dist[tmp->num]) {
                    dist[tmp->num] = dist[row] + tmp->weight;
                }
            }
            tmp = tmp->next;
        }

    }
    printf("%d\n", dist[t]);
    free(dist);
    free(visited);
}


int main() {
    int i;
    int n, m, p;
    int u, v, w;
    int s, t;

    scanf("%d %d %d", &n, &m, &p);

    vertex_t **list = malloc(sizeof(vertex_t*)*n);

    for (i=0; i<m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        append(list, u, v, w);
    }

    for (i=0; i<p; i++) {
        scanf("%d %d", &s, &t);
        bfs(list, s, t, n);
    }

    return 0;
}