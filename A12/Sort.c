#include <stdio.h>
#include <stdlib.h>

int *createArr(int n) {
    int *arr = (int*)malloc(sizeof(int) * n);
    return arr;
}

void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

// selection sort
void selection_sort(int arr[], int n) {
    int i, j;
    for (i=0; i<n-1; i++) {
        int min = i;
        for (j=i; j<n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (i!=min) swap(arr, i, min);
    }
}

//insertion sort
void insertion_sort(int arr[], int n) {
    int i, j;
    for (i=1; i<n; i++) {
        for (j=0; j<i; j++) {
            if (arr[i] < arr[j]) {
                while(j < i) {
                    swap(arr, i, j);
                    j++;
                }
            }
        }
    }
}

//bubble sort
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (arr[j+1] < arr[j]) swap(arr, j, j+1);
        }
    }
}

//merge_sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int nl = m-l+1;
    int nr = r-m;
    int left[nl];
    int right[nr];
    
    //Copy data to left and right
    for (i=0; i<nl; i++) {
        left[i] = arr[l+i];
    }
    for (j=0; j<nr; j++) {
        right[j] = arr[m+1+j];
    }

    //Merge the left and right back into arr
    i = 0, j = 0, k = l;
    while (i<nl && j<nr) {
        // arr[k++] = (left[i]<=right[j])? left[i++] : right[j++];
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        // arr[k++] = left[i++];
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j <nr) {
        // arr[k++] = right[j++];
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

//quick sort
// ขก.

void print_arr(int arr[], int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = createArr(n);
    int i;
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // selection_sort(arr, n);
    // insertion_sort(arr, n);
    // bubble_sort(arr, n);
    // merge_sort(arr, 0, n-1);
    print_arr(arr, n);
    
    return 0;
}