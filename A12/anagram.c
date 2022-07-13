#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char word[51];
    char word_sorted[51];
} data_t;

void swap(char a[], int i, int j) {
	int tmp;
	while (j < i) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		j++;
	}
}

void insert_sort(char a[], int n) {
	int i, j;
	for (i=1; i<n; i++) {
		for (j=0; j<i; j++) {
			if (a[i] < a[j]) {
				swap(a, i, j);
				break;
			} 
		}
	}
}

int main() {
    int m, n;
    int i, j;

    scanf("%d %d", &m, &n);
    data_t *arr = (data_t*)malloc(sizeof(data_t)*m);
    for (i=0; i<m; i++) {
        scanf("%s", arr[i].word);
        strcpy(arr[i].word_sorted, arr[i].word);
        insert_sort(arr[i].word_sorted, strlen(arr[i].word));
    }
    
    char check[51];
    for (i=0; i<n; i++) {
        scanf("%s", check);
        insert_sort(check, strlen(check));
        for (j=0; j<m; j++) {
            if (strcmp(arr[j].word_sorted, check) == 0) {
                printf("%s ", arr[j].word);
            }
        }
        printf("\n");
    }    
    return 0;
}