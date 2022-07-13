#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key) {
    hash_t *h = (hash_t*)malloc(sizeof(hash_t));
    h->table = (item_t**)malloc(sizeof(item_t*)*m);
    h->size = m;
    h->hash_key = hash_key;
    return h;
}

char *copyString(char *text) {
    char *tmp = (char*)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp, text);
    return tmp;
}

item_t *createItem(char *text) {
    item_t *i = (item_t*)malloc(sizeof(item_t));
    i->text = copyString(text);
    i->next = NULL;
    return i;
}

int hash(hash_t *h, char *text) {
    unsigned int hash_value = 0;
    int i;
    for (i=0; i<strlen(text); i++) {
        hash_value = h->hash_key*hash_value + text[i];
    }
    return hash_value % h->size;
}

void insert(hash_t *h, char *text) {
    item_t *newItem = createItem(text);
    int index = hash(h, text);
    if (h->table[index] == NULL) h->table[index] = newItem;
    else {
        item_t *tmp = h->table[index];
        h->table[index] = newItem;
        newItem->next = tmp;
    }
}

int search(hash_t *h, char *text) {
    int index = hash(h, text);
    item_t *tmp = h->table[index];
    while(1) {
        if (tmp == NULL) return -1;
        if (strcmp(tmp->text, text) == 0) return index;
        tmp = tmp->next;
    }
}

int main(void) {
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char*)malloc(sizeof(char)*TEXTSIZE);

    for (i=0; i<n; i++) {
        scanf("%d %s", &command, text);
        switch(command) {
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n", search(hashtable, text));
                break;
        }
    }
    return 0;
}