#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10000
typedef struct node{
    int t;
    int n;
    double f;
    char str[11];
    struct node *next;
}node_t;

void append(node_t **head){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->next = NULL;
    int type;
    scanf(" %d",&type);
    newNode->t = type;
    if (type==0) scanf("%d",&newNode->n);
    else if (type==1) scanf("%lf",&newNode->f);
    else scanf("%s",newNode->str);
    if (*head == NULL) *head = newNode;
    else{
        node_t *tmp = *head;
        while (tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void get(node_t *head){
    int pos,count = 0;
    scanf(" %d",&pos);
    node_t *tmp = head;
    while (count!=pos){
        tmp = tmp->next;
        count++;
    }
    if (tmp->t==0) printf("%d\n",tmp->n);
    else if (tmp->t==1) printf("%lf\n",tmp->f);
    else printf("%s\n",tmp->str);
}
void show(node_t *head){
    node_t *tmp = head;
    while (tmp!=NULL){
        if (tmp->t==0) printf("%d ",tmp->n);
        else if (tmp->t==1) printf("%lf ",tmp->f);
        else printf("%s ",tmp->str);
        tmp = tmp->next;
    }
    printf("\n");
}
void show_reverse(node_t *head){
    int count = 0,i;
    node_t rem[SIZE],*tmp = head;
    while (tmp!=NULL){
        rem[count].t = tmp->t;
        if (tmp->t==0) rem[count].n = tmp->n;
        else if (tmp->t==1) rem[count].f = tmp->f;
        else strcpy(rem[count].str,tmp->str);
        tmp = tmp->next;
        count++;
    }
    for (i=count-1;i>=0;i--){
        if (rem[i].t==0) printf("%d ",rem[i].n);
        else if (rem[i].t==1) printf("%lf ",rem[i].f);
        else printf("%s ",rem[i].str);
    }
    printf("\n");
}
void insert(node_t *head){
    node_t *tmp = head;
    int pos,count = 0;
    scanf(" %d",&pos);
    while (count!=pos){
        tmp = tmp->next;
        count++;
    }
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->next = tmp->next;
    tmp->next = newNode;
    int type;
    scanf("%d",&type);
    newNode->t = type;
    if (type==0) scanf("%d",&newNode->n);
    else if(type==1) scanf("%lf",&newNode->f);
    else scanf("%s",newNode->str);
}
void delete(node_t **head){
    node_t *tmp = *head,*delNode;
    int pos,count = 1;
    scanf(" %d",&pos);
    while (count<pos){
        tmp = tmp->next;
        count++;
    }
    if (pos==0){
        delNode = tmp;
        *head = tmp->next;
    }
    else{
        delNode = tmp->next;
        tmp->next = tmp->next->next;
    }
    free(delNode);
}
void change(node_t *head){
    node_t *tmp = head;
    int type,pos,count = 0;
    scanf(" %d",&pos);
    while(count!=pos){
        tmp = tmp->next;
        count++;
    }
    scanf("%d",&type);
    tmp->t = type;
    if (type==0) scanf("%d",&tmp->n);
    else if(type==1) scanf("%lf",&tmp->f);
    else scanf("%s",tmp->str);
}
void is_empty(node_t *head){
    if (head==NULL) printf("Empty\n");
    else printf("Not Empty\n");
}
void length(node_t *head){
    int len = 0;
    node_t *tmp = head;
    while (tmp!=NULL){
        tmp = tmp->next;
        len++;
    }
    printf("%d\n",len);
}
int main(){
    node_t *head = NULL;
    int n,i;
    char command;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&command);
        switch (command){
            case 'A':
                append(&head);
                break;
            case 'G':
                get(head);
                break;
            case 'S':
                show(head);
                break;
            case 'R':
                show_reverse(head);
                break;
            case 'I':
                insert(head);
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