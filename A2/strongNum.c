#include<stdio.h>

int fac(int n){
    if (n==0 || n==1) return 1;
    else return n * fac(n-1);
}

int strNum(int n){
    int res = 0;
    while (n!=0){
        res += fac(n%10);
        n /= 10;
    }
    return res;
}

int main(){
    int n,m;
    int i,j;
    int res,max_strNum;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&m);
        max_strNum = 0;
        for (j=1;j<m;j++){
            res = strNum(j);
            if (res==j && max_strNum<res) max_strNum = res;
        }
        printf("%d\n",max_strNum);
    }
    return 0;
}