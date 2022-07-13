#include<stdio.h>
#include<stdlib.h>
int count_s = 0;
int count_q = 0;
typedef struct node{
    char data;
    struct node* next;
}node_t;

typedef struct queue{
    node_t* front;
    node_t* rear;
}queue_t;

void enqueue(queue_t* q,char ch){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = ch;
    newNode->next = q->rear;
    q->rear = newNode;
    if (q->front == NULL) q->front = newNode;
    count_q++;
}

void dequeue(queue_t* q){
    node_t* tmp_rear = q->rear,*tmp_front = q->front;
    if (q->rear == q->front) q->rear = NULL,q->front = NULL;
    else{
        while (tmp_rear->next != q->front) tmp_rear = tmp_rear->next;
        q->front = tmp_rear;
    }
    free(tmp_front);
    count_q--;
}

// void showQueue(queue_t q){
//     node_t *tmp_rear = NULL,*tmp_front = q.front;
//     if (q.front == NULL) printf("Queue is empty.\n");
//     else{
//         while (q.rear != tmp_front){
//             tmp_rear = q.rear;
//             while (tmp_rear->next != tmp_front) tmp_rear = tmp_rear->next;
//             printf("%c ",tmp_front->data);
//             tmp_front = tmp_rear;
//         }
//         if (q.rear == tmp_front) printf("%c ",tmp_front->data);
//         printf("\n");
//     }
// }

void push(node_t** s,char ch){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = ch;
    newNode->next = *s;
    *s = newNode;
    count_s++;
}

node_t* pop(node_t* s){
    node_t* tmp = s;
    s = s->next;
    free(tmp);
    count_s--;
    return s;
}

int main(){
    node_t* s = NULL;
    queue_t q = {NULL,NULL};
    char ch;
    int palin = 1;
    while (1){
        scanf("%c",&ch);
        if (ch=='x') break;
        enqueue(&q,ch);
    }
    while (1){
        scanf("%c",&ch);
        if (ch=='y') break;
        push(&s,ch);
    }
    while(1){
        // showQueue(q);
        if (count_q != count_s){
            palin = 0;
            break;
        }
        if (q.front==NULL && s==NULL) break;
        if (q.front->data != s->data){
            palin = 0;
            break;
        }
        dequeue(&q);
        s = pop(s);
    }
    printf("%d\n",palin);
    return 0;
}