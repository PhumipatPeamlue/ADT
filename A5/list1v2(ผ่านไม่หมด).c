#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
typedef struct node{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *head){
    int value;
    scanf("%d",&value);
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    else{
        node_t *NODE = head;
        while (NODE->next != NULL) NODE = NODE->next;
        NODE->next = newNode;
        return head;
    }
}

void get(node_t *head){
    int position,count = 0;
    scanf("%d",&position);
    node_t *NODE = head;
    while (NODE != NULL){
        if (count == position){
            printf("%d ",NODE->data);
            break;
        }
        NODE = NODE->next;
        count++;
    }
    printf("\n");
}

void show(node_t *head){
    node_t *NODE = head;
    while (NODE != NULL){
        printf("%d ",NODE->data);
        NODE = NODE->next;
    }
    printf("\n");
}

void reverse(node_t *head){
    int allData[SIZE],i = 0,j;
    node_t *NODE = head;
    while (NODE != NULL){
        allData[i] = NODE->data;
        NODE = NODE->next;
        i++;
    }
    NODE = head;
    for (j=i-1;j>=0;j--){
        NODE->data = allData[j];
        NODE = NODE->next;
    }
}

int main(){
    node_t *startNode = NULL;
    int n,i;
    char command;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&command);
        switch (command){
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                reverse(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}