#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef struct node {
    int type;
    char data_c;
    float data_f;
    struct node* previous;
    struct node* next;
}node_t;

node_t* append(node_t* head,char ch){
    count++;
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->previous = NULL;
    newNode->next = NULL;
    if (ch-48 >= 0 && ch-48 <= 9){
        newNode->data_f = ch-48;
        newNode->type = 1;
    }
    else{
        newNode->data_c = ch;
        newNode->type = 2;
    }
    if (head == NULL) return newNode;
    else{
        node_t *Node = head;
        while (Node->next!=NULL) Node = Node->next;
        newNode->previous = Node;
        Node->next = newNode;
    }
    return head;
}

// void show(node_t *head){
//     node_t *tmp = head;
//     while (tmp!=NULL){
//         if (tmp->type==1) printf("%.2f %d\n",tmp->data_f,tmp->type);
//         else if (tmp->type==2) printf("%c %d\n",tmp->data_c,tmp->type);
//         tmp = tmp->next;
//     }
//     printf("\n");
// }

float cal(float num1,float num2,char op){
    if (op=='+') return num1+num2;
    else if (op=='-') return num1-num2;
    else if (op=='*') return num1*num2;
    else return num1/num2;

}

node_t* posfix(node_t* head){
    node_t* Node = head;
    while(1){
        if (Node->type==1 && Node->next->type==1 && Node->next->next->type==2) break;
        Node = Node->next;
    }
    // printf("pass\n");
    // printf("%.2f\n",Node->data_f);
    char op = Node->next->next->data_c;
    float num1 = Node->data_f,num2 = Node->next->data_f;
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (count == 3){
        count = 0;
        newNode->data_f = cal(num1,num2,op);
        newNode->previous = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else{
        if (Node == head){
            head = newNode;
            newNode->previous = NULL;
        }
        else{
            newNode->previous = Node->previous;
            newNode->previous->next = newNode;
        }
        newNode->next = Node->next->next->next;
        newNode->next->previous = newNode;
        newNode->type = 1;
        newNode->data_f = cal(num1,num2,op);
        count -= 2;
    }
    free(Node->next->next);
    free(Node->next);
    free(Node);
    return head;
}

int main(){
    node_t* head = NULL;
    int i,n;
    char ch;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&ch);
        head = append(head,ch);
    }
    // show(head);
    // printf("%d\n",count);
    while (count != 0) head = posfix(head);
    printf("%.2f\n",head->data_f);
    return 0;
}