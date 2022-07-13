#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int i, int j) {
	int tmp;
	while (j < i) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		j++;
	}
}

void insert_sort(int a[], int n) {
	int i, j;
	for (i=1; i<n; i++) {
		for (j=0; j<i; j++) {
			if (a[i] < a[j]) {
				swap(a, i, j);
				break;
			} 
		}
		for (j=0; j<n; j++) printf("%d ", a[j]);
		printf("\n");
	}
}

int main() {
	int n, i;

	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	insert_sort(arr, n);
	return 0;
}
