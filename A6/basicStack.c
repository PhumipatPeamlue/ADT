#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t Stack_t;

int count = 0;
Stack_t *push(Stack_t *s,int value){
    Stack_t *Node = (Stack_t*)malloc(sizeof(Stack_t));
    Node->data = value;
    Node->next = s;
    count++;
    return Node;
}

void top(Stack_t *s){
    if (s == NULL) printf("Stack is empty.\n");
    else printf("%d\n",s->data);
}

Stack_t *pop(Stack_t *s){
    if (s == NULL) return s;
    Stack_t *tmp = s;
    s = s->next;
    free(tmp);
    count--;
    return s;
}

void size(Stack_t *s){
    printf("%d\n",count);
}

void empty(Stack_t *s){
    if (s == NULL) printf("Stack is empty.\n");
    else printf("Stack is not empty.\n");
}

int main(void){
    Stack_t *s = NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch(command) {
            case 1:
                scanf("%d",&value);
                s = push(s,value);
                break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
                break;
        }
    }
    return 0;
}