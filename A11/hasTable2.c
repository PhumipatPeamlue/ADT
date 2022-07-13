#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key) {
  hash_t *h = (hash_t*)malloc(sizeof(hash_t));
  h->table = (item_t*)malloc(sizeof(item_t)*m);
  h->size = m;
  h->hash_key = hash_key;
  return h;
}

char *copyString(char *text) {
  char *tmp = (char*)malloc(sizeof(char)*TEXTSIZE);
  strcpy(tmp, text);
  return tmp;
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
  int init = hash(h, text), index;
  int i;
  for (i=0; i<h->size; i++) {
    index = (init + (i + i*i)/2) % h->size;
    if (h->table[index] == NULL) {
      h->table[index] = copyString(text);
      return;
    }
  }
}

int search(hash_t *h, char *text) {
  int init = hash(h, text), index;
  int i;
  for (i=0; i<h->size; i++) {
    index = (init + (i + i*i)/2) % h->size;
    if (h->table[index] == NULL) return -1;
    if (strcmp(h->table[index], text) == 0) return index;
  }
  return -1;   
}

int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
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