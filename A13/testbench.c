#include <stdio.h>
#include <stdlib.h>
#define v 9

int main() {
    int n;
    scanf("%d", &n);

    int **graph = (int**)malloc(sizeof(int*) * n);
    int i;
    for (i=0; i<n; i++) {
        *(graph + i) = (int*)malloc(sizeof(int) * n);
    }

    int j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", *(graph + i) + j);
        }
    }

    printf("%d\n", *(*(graph + 1) + 2));
    return 0;
}
