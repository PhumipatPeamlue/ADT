#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t queue_t;

queue_t *front = NULL;
int count = 0;
queue_t *enqueue(queue_t *q,int value){
    queue_t *Node = (queue_t*)malloc(sizeof(queue_t));
    Node->data = value;
    Node->next = q;
    q = Node;
    if (front == NULL) front = Node;
    count++;
    return q;
}

queue_t *dequeue(queue_t *q){
    queue_t *tmp = NULL,*tmp_q = q;
    if (q == NULL){
        printf("Queue is empty.\n");
        return q;
    }
    tmp = front;
    if (q == front) q = NULL,front = NULL;
    else{
        while (tmp_q->next != front) tmp_q = tmp_q->next;
        tmp_q->next = NULL;
        front = tmp_q;
    }
    printf("%d\n",tmp->data);
    free(tmp);
    count--;
    return q;
}

void show(queue_t *q){
    queue_t *tmp_q = NULL,*tmp_front = front;
    if (front == NULL) printf("Queue is empty.\n");
    else{
        while (q != tmp_front){
            tmp_q = q;
            while (tmp_q->next != tmp_front) tmp_q = tmp_q->next;
            printf("%d ",tmp_front->data);
            tmp_front = tmp_q;
            // printf("IN LOOP ");
        }
        if (q == tmp_front) printf("%d ",tmp_front->data);
        printf("\n");
    }
}

void empty(queue_t *q){
    if (q == NULL) printf("Queue is empty.\n");
    else printf("Queue is not empty.\n");
}

void size(queue_t *q){
    printf("%d\n",count);
}

int main(void){
    queue_t *q = NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch(command){
            case 1:
                scanf("%d", &value);
                q = enqueue(q,value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}