#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char c;
    struct node *next;
}Stack_t;

void push(Stack_t **t,char c){
    Stack_t *newNode = (Stack_t*)malloc(sizeof(Stack_t));
    newNode->c = c;
    newNode->next = *t;
    *t = newNode;
}

Stack_t *pop(Stack_t *t){
    if (t == NULL) return t;
    Stack_t *tmp = t;
    t = t->next;
    free(tmp);
    return t;
}

int empty(Stack_t *t){
    if (t == NULL) return 1;
    return 0;
}

int main(){
    int n,i,check = 1;
    char wonglep;
    Stack_t *top = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&wonglep);
        if (wonglep=='[' || wonglep=='{' || wonglep=='('){
            push(&top,wonglep);
        }
        else if ((wonglep==']' || wonglep=='}' || wonglep==')') && empty(top)){
            check = 0;
            break;
        }
        else if (top->c=='[' && wonglep==']') top = pop(top);
        else if (top->c=='{' && wonglep=='}') top = pop(top);
        else if (top->c=='(' && wonglep==')') top = pop(top);
        else{
            check = 0;
            break;
        }
    }
    printf("%d\n",check);
    return 0;
}