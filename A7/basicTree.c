#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
typedef struct tree{
    int value;
    struct tree *first_child;
    struct tree *next_sibling;
}tree_t;

int countDepth = 0,countNode = 0;
tree_t *searchNode(tree_t *t,int v){
    if (t == NULL){
        countDepth--;
        return t;
    }
    if (t->value == v){
        return t;
    }
    countDepth++;
    tree_t *pos = searchNode(t->first_child,v);
    if (pos != NULL){
        return pos;
    }
    else {
        return searchNode(t->next_sibling,v);
    }
}

tree_t *search_preNode(tree_t *t,tree_t *pre_node,int v){
    if (t == NULL){
        return t;
    }
    if (t->value == v){
        return pre_node;
    }
    tree_t *pos = search_preNode(t->first_child,t,v);
    if (pos != NULL){
        return pos;
    }
    else{
        return search_preNode(t->next_sibling,t,v);
    }
}

tree_t * createNode(int v){
    tree_t *newNode = (tree_t*)malloc(sizeof(tree_t));
    newNode->value = v;
    newNode->first_child = NULL;
    newNode->next_sibling = NULL;
    return newNode;
}

tree_t *attach(tree_t *t,int parent,int child){
    tree_t *newNode = createNode(child);
    if (parent == -1){
        countNode++;
        return newNode;
    }
    tree_t *pos = searchNode(t,parent);
    if (pos->first_child == NULL){
        pos->first_child = newNode;
    } 
    else{
        pos = pos->first_child;
        while (pos->next_sibling != NULL){ 
            pos = pos->next_sibling;
        }
        pos->next_sibling = newNode;
    }
    countNode++;
    return t;
}

tree_t *detach(tree_t *t,int node){
    if (t == NULL || t->value == node){
        t = NULL;
    }
    else{
        int type;
        tree_t *pre_pos = search_preNode(t,NULL,node);
        tree_t *pos = NULL, *tmp = NULL, *del = NULL;
        if (pre_pos->first_child != NULL && pre_pos->first_child->value == node){
            pos = pre_pos->first_child;
            type = 0;
        }
        else{
            pos = pre_pos->next_sibling;
            type = 1;
        }
        while (pos->first_child != NULL){
            tmp = pos;
            while (tmp->first_child->first_child != NULL){
                tmp = tmp->first_child;
            }
            del = tmp->first_child;
            if (del->next_sibling == NULL){
                tmp->first_child = NULL;
            }
            else{
                tmp->first_child = del->next_sibling;
            }
            free(del);
        }
        if (type == 0){
            if (pos->next_sibling == NULL){
                pre_pos->first_child = NULL;
            }
            else{
                pre_pos->first_child = pos->next_sibling;
            }
        }
        else{
            if (pos->next_sibling == NULL){
                pre_pos->next_sibling = NULL;
            }
            else{
                pre_pos->next_sibling = pos->next_sibling;
            }
        }
        free(pos);
    }
    countNode--;
    return t;
}

int search(tree_t *t,int node){
    if (searchNode(t,node) == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int degree(tree_t *t,int node){
    tree_t *pos = searchNode(t,node);
    if (pos->first_child == NULL){
        return 0;
    }
    else{
        int count = 1;
        pos = pos->first_child;
        while (pos->next_sibling != NULL){
            pos = pos->next_sibling;
            count++;
        }
        return count;
    }
}

int is_root(tree_t *t,int node){
    if (t->value == node){
        return 1;
    }
    else{
        return 0;
    }
}

int is_leaf(tree_t *t,int node){
    tree_t *pos = searchNode(t,node);
    if (pos->first_child == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void siblings(tree_t *t,int node){
    if (t == NULL || t->value == node){
        printf("\n");
    }
    else{
        tree_t *pos = NULL, *pre_pos = NULL;
        int tmp_node = node;
        while(1){
            pos = searchNode(t,tmp_node);
            pre_pos = search_preNode(t,NULL,tmp_node);
            if (pre_pos->next_sibling != pos){
                break;
            }
            tmp_node = pre_pos->value;
        }
        while (pos != NULL){
            if (pos->value != node){
                printf("%d ",pos->value);
            }
            pos = pos->next_sibling;
        }
        printf("\n");
    }
}

int depth(tree_t *t,int node){
    countDepth = 0;
    tree_t *pos = searchNode(t,node);
    if (pos == t){
        return 0;
    }
    else{
        return countDepth;
    }
}

int pathLength = 0;
tree_t* find_path(tree_t *t,int v,int *m,int *i){
    if (t == NULL){
        return t;
    }
    if (t->value == v){
        *i = 0;
        *(m + *i) = v;
        return t;
    }
    tree_t *pos = find_path(t->first_child,v,m,i);
    if (pos != NULL){
        *i = *i + 1;
        *(m + *i) = t->value;
        return pos;
    }
    else{
        return find_path(t->next_sibling,v,m,i);
    }
}
void print_path(tree_t *t,int start,int end){
    int *mapping = (int*)malloc(sizeof(int));
    tree_t *pos = searchNode(t,start);
    pos = find_path(pos,end,mapping,&pathLength);
    int i;
    for (i=pathLength;i>=0;i--){
        printf("%d ",mapping[i]);
    }
    printf("\n");
    free(mapping);
}

tree_t* calPathLength(tree_t *t,int v,int *i){
    if (t == NULL){
        return t;
    }
    if (t->value == v){
        *i = 1;
        return t;
    }
    tree_t *pos = calPathLength(t->first_child,v,i);
    if (pos != NULL){
        *i = *i + 1;
        return pos;
    }
    else{
        return calPathLength(t->next_sibling,v,i);
    }
}
int path_length(tree_t *t,int start,int end){
    tree_t *pos = searchNode(t,start);
    pos = calPathLength(pos,end,&pathLength);
    return pathLength;
} 

void ancester(tree_t *t,int node){
    int *mapping = (int*)malloc(sizeof(int)*countNode);
    tree_t *pos = NULL;
    pos = find_path(t,node,mapping,&pathLength);
    int i;
    for (i=pathLength;i>=0;i--){
        printf("%d ",mapping[i]);
    }
    printf("\n");
    free(mapping);
}

typedef struct node {
    tree_t *tpos;
    struct node *next;
}node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
}queue_t;

queue_t enqueue(queue_t q,tree_t *t){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->tpos = t;
    newNode->next = q.rear;
    q.rear = newNode;
    if (q.front == NULL) q.front = newNode;
    return q;
}

queue_t dequeue(queue_t q,tree_t **node){
    if (q.rear == NULL){
        return q;
    }
    node_t *delete = q.front;
    if (q.rear == q.front){
        q.rear = NULL;
        q.front = NULL;
    }
    else{
        node_t *tmp_rear = q.rear;
        while (tmp_rear->next != q.front){
            tmp_rear = tmp_rear->next;
        }
        tmp_rear->next = NULL;
        q.front = tmp_rear;
    }
    *node = delete->tpos;
    free(delete);
    return q;
}

void descendant(tree_t *t,int v){
    queue_t q = {NULL,NULL};
    tree_t *root = searchNode(t,v);
    q = enqueue(q,root);
    while (q.rear != NULL && q.front != NULL){
        tree_t *pos = NULL;
        q = dequeue(q,&pos);
        printf("%d ",pos->value);
        if (pos->first_child == NULL){
            continue;
        }
        else{
            pos = pos->first_child;
            while (pos != NULL){
                q = enqueue(q,pos);
                pos = pos->next_sibling;
            }
        }
    }
    printf("\n");
}

void bfs(tree_t *t){
    descendant(t,t->value);
}

int countrecursive = 0;
void dfs(tree_t *t){
    if (t == NULL){
        return;
    }
    printf("%d ",t->value);
    dfs(t->first_child);
    dfs(t->next_sibling);
    countrecursive++;
    if (countrecursive == countNode){
        printf("\n");
        countrecursive = 0;
    }
}

void map_tree(tree_t *t,tree_t **member){
    if (t == NULL){
        return;
    }
    member[countrecursive] = t;
    countrecursive++;
    map_tree(t->first_child,member);
    map_tree(t->next_sibling,member);
    if (countrecursive == countNode){
        countrecursive = 0;
    }
}
void print_tree(tree_t *t){
    tree_t *member[SIZE];
    map_tree(t,member);
    int i,j;
    for (i=0;i<countNode;i++){
        for (j=0;j<depth(t,member[i]->value);j++){
            printf("    ");
        }
        printf("%d\n",member[i]->value);
    }
}

int main(){
    tree_t *t = NULL;
    int n,i,command;
    int parent,child,node,start,end;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&command);
        switch (command){
            case 1:
                scanf("%d %d",&parent,&child);
                t = attach(t,parent,child);
                break;
            case 2:
                scanf("%d",&node);
                t = detach(t,node);
                break;
            case 3:
                scanf("%d",&node);
                printf("%d\n",search(t,node));
                break;
            case 4:
                scanf("%d",&node);
                printf("%d\n",degree(t,node));
                break;
            case 5:
                scanf("%d",&node);
                printf("%d\n",is_root(t,node));
                break;
            case 6:
                scanf("%d",&node);
                printf("%d\n",is_leaf(t,node));
                break;
            case 7:
                scanf("%d",&node);
                siblings(t,node);
                break;
            case 8:
                scanf("%d",&node);
                printf("%d\n",depth(t,node));
                break;
            case 9:
                scanf("%d %d",&start,&end);
                print_path(t,start,end);
                break;
            case 10:
                scanf("%d %d",&start,&end);
                printf("%d\n",path_length(t,start,end));
                break;
            case 11:
                scanf("%d",&node);
                ancester(t,node);
                break;
            case 12:
                scanf("%d",&node);
                descendant(t,node);
                break;
            case 13:
                bfs(t);
                break;
            case 14:
                dfs(t);
                break;
            case 15:
                print_tree(t);
                break;
        }
    }
    return 0;
}