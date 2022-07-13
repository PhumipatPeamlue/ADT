#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
int n,k,number = 1;
typedef struct node{
    int number;
    int limit;
    struct node *next;
}node_t;
void createNode(node_t **head,int lim){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->number = number;
    newNode->limit = lim;
    newNode->next = NULL;
    if (*head == NULL) *head = newNode;
    else{
        node_t *tmp = *head;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = newNode;
        if (number == n) newNode->next = *head;
    }
    number++;
}
int checkDigit(int x){
    int temp[10],i;
    for(i=0;i<8;i++){
        temp[i] = x%10; 
        x/=10;
    }
    for(i=0;i<8;i++){
        if (temp[i] == k) return 1;
    }
    return -1;
}
void countGame(node_t *head){
    node_t *tmp = head,*pre = NULL;
    int count = 1;
    
    while (1){
        int have = checkDigit(count);
        if (count%k == 0 || have == 1){
            tmp->limit--;
            if (tmp->limit<0){
                pre->next = pre->next->next;
                tmp = tmp->next;
                count++;
                if (pre == pre->next){
                    printf("%d\n",tmp->number);
                    break;
                }
                continue;
            }
        }
        pre = tmp;
        tmp = tmp->next;
        count++;
    }
}
int main(){
    int i,limit;
    node_t *head = NULL;
    scanf("%d %d",&n,&k);
    for (i=0;i<n;i++){
        scanf("%d",&limit);
        createNode(&head,limit);
    }
    countGame(head);
    return 0;
}