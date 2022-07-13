#include<stdio.h>

void convertNum(int n){
    char *romanNum[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int Num[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int i,j=0;
    while (n>0){
        // printf("%d\n",n/Num[j]);
        for (i=0;i<n/Num[j];i++){
            printf("%s",romanNum[j]);
        }
        if (n/Num[j]!=0) n %= Num[j];
        j++;
    }
    printf("\n");
}

int main(){
    int N,n;
    int i;

    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d",&n);
        convertNum(n);
    }

    return 0;
}