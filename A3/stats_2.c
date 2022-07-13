#include<stdio.h>
#include<stdlib.h>

void findStats(int n,int *a,int* maxi,int* mini,double* avg){
    int i;
    *maxi = *a,*mini = *a;
    *avg = 0;
    for (i=0;i<n;i++){
        if (*maxi < *(a+i)) *maxi = *(a+i);
        if (*(a+i) < *mini) *mini = *(a+i);
        *avg += *(a+i);
    }
    *avg /= n;
}

int main(){
    int n,i,maxi,mini;
    double avg;
    int* nums;

    scanf("%d", &n);
    nums = (int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++){
        scanf("%d",nums+i);
    }
    findStats(n,nums,&maxi,&mini,&avg);
    printf("%.2f %d %d\n",avg,maxi,mini);
    return 0;
}