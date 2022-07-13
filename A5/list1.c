#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;
node_t *append(node_t **head){
    int value;
    scanf(" %d",&value);
    node_t *tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = value;
    tmp->next = NULL;
    if (*head==NULL){
        *head = tmp;
    }
    else{
        node_t *Node  = *head;
        while (1){
            if (Node->next==NULL){
                Node->next = tmp;
                break;
            }
            Node = Node->next;
        }
    }
    return *head;
}
void get(node_t *head){
    int index,count = 0;
    scanf(" %d",&index);
    node_t *tmp = head;
    while (1){
        if (count==index){
            printf("%d\n",tmp->data);
            break;
        }
        tmp = tmp->next;
        count++;
    }
}
void show(node_t *head){
    node_t *tmp = head;
    while (tmp!=NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
node_t *reverse(node_t **head){
    node_t *tmp = *head;
    int num[100],count = 0,i;
    while (tmp!=NULL){
        num[count] = tmp->data;
        tmp = tmp->next;
        count++;
    }
    tmp = *head;
    for (i=count-1;i>=0;i--){
        tmp->data = num[i];
        tmp = tmp->next;
    }
    return *head;
}
node_t *cut(node_t **head){
    int start,end,count = 0;
    scanf(" %d %d",&start,&end);
    node_t *tmp = *head;
    while (1){
        if (count==start){
            *head = tmp;
        }
        if (count==end){
            tmp->next = NULL;
            return *head;
        }
        tmp = tmp->next;
        count++;
    }
}
int main(){
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c", &command);
        switch (command){
            case 'A':
                startNode = append(&startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(&startNode);
                break;
            case 'C':
                startNode = cut(&startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}