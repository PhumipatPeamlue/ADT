#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int type;
    int data_int;
    double data_double;
    char data_str[11];
    struct node *previous;
    struct node *next;
}node_t;

void append(node_t **head,node_t **tail){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->previous = NULL;
    newNode->next = NULL;
    *tail = newNode;
    scanf("%d",&newNode->type);
    if (newNode->type==0) scanf("%d",&newNode->data_int);
    else if (newNode->type==1) scanf("%lf",&newNode->data_double);
    else scanf("%s",newNode->data_str);
    if (*head == NULL) *head = newNode;
    else{
        node_t *tmp = *head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->previous = tmp;

    }
}

void get(node_t *head){
    int pos = 0,printPos;
    node_t *tmp = head;
    scanf("%d",&printPos);
    while (pos<printPos) tmp = tmp->next,pos++;
    if (tmp->type==0) printf("%d ",tmp->data_int);
    else if (tmp->type==1) printf("%lf ",tmp->data_double);
    else printf("%s ",tmp->data_str);
    printf("\n");
}

void show(node_t *head){
    node_t *tmp = head;
    while (tmp != NULL){
        if (tmp->type==0) printf("%d ",tmp->data_int);
        else if (tmp->type==1) printf("%lf ",tmp->data_double);
        else printf("%s ",tmp->data_str);
        tmp = tmp->next;
    }
    printf("\n");
}

void show_reverse(node_t *tail){
    node_t *tmp = tail;
    while (tmp != NULL){
        if (tmp->type==0) printf("%d ",tmp->data_int);
        else if (tmp->type==1) printf("%lf ",tmp->data_double);
        else printf("%s ",tmp->data_str);
        tmp = tmp->previous;
    }
    printf("\n");
}

void insert(node_t *head,node_t **tail){
    int insertAfter,pos = 0;
    scanf("%d",&insertAfter);
    node_t *tmp = head;
    while (pos<insertAfter && tmp->next!=NULL) tmp = tmp->next,pos++;
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (tmp->next == NULL){
        *tail = newNode;
        newNode->previous = tmp;
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    else{
        newNode->previous = tmp;
        newNode->next = tmp->next;
        tmp->next->previous = newNode;
        tmp->next = newNode;
    }
    scanf("%d",&newNode->type);
    if (newNode->type==0) scanf("%d",&newNode->data_int);
    else if (newNode->type==1) scanf("%lf",&newNode->data_double);
    else scanf("%s",newNode->data_str);
}

void delete(node_t **head){
    int pos = 0,delPos;
    node_t *tmp = *head;
    scanf("%d",&delPos);
    while (pos < delPos && tmp->next != NULL) tmp = tmp->next,pos++;
    if (pos==0) *head = tmp->next;
    else tmp->previous->next = tmp->next;
}

void change(node_t *head){
    int pos = 0,chPos;
    node_t *tmp = head;
    scanf("%d",&chPos);
    while (pos<chPos) tmp = tmp->next,pos++;
    scanf("%d",&tmp->type);
    if (tmp->type==0) scanf("%d",&tmp->data_int);
    else if (tmp->type==1) scanf("%lf",&tmp->data_double);
    else scanf("%s",tmp->data_str);
}
void is_empty(node_t *head){
    if (head == NULL) printf("Empty\n");
    else printf("Not empty\n");
}

void length(node_t *head){
    int len = 0;
    node_t *tmp = head;
    while (tmp != NULL) tmp = tmp->next,len++;
    printf("%d\n",len);
}
int main(){
    node_t *head = NULL,*tail = NULL;
    int n,i;
    char cmd;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&cmd);
        switch (cmd){
            case 'A':
                append(&head,&tail);
                break;
            case 'G':
                get(head);
                break;
            case 'S':
                show(head);
                break;
            case 'R':
                show_reverse(tail);
                break;
            case 'I':
                insert(head,&tail);
                break;
            case 'D':
                delete(&head);
                break;
            case 'C':
                change(head);
                break;
            case 'E':
                is_empty(head);
                break;
            case 'L':
                length(head);
                break;
            default:
                break;
        }
    }
    return 0;
}