#include <stdio.h>
#include <string.h>

unsigned long int hash(char *text) {
    unsigned int hash_value = 0;
    int i;
    for (i=0; i<strlen(text); i++) {
        hash_value = 93*hash_value + text[i];
    }
    return hash_value % 211;
}

int main() {
    char text[100];
    scanf("%s", text);
    printf("%lu\n", hash(text));
}