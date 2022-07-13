#include<stdio.h>
#include<string.h>
#define SIZE 100000
int rem = 0;
char num1[SIZE],num2[SIZE],res[SIZE];
int main(){
    scanf("%s",num1);
    scanf("%s",num2);
    if (strlen(num1)<strlen(num2)){
        char tmp[SIZE];
        strcpy(tmp,num1);
        strcpy(num1,num2);
        strcpy(num2,tmp);
    }
    int i = 0,j,len1 = strlen(num1)-1 ,len2 = strlen(num2)-1;
    while (1){
        if (len1<0 && rem==0) break;
        int sum = 0;
        if (len2>=0) sum = (num1[len1] - '0') + (num2[len2] - '0');
        else if (len1>=0) sum = (num1[len1] - '0');
        res[i] = (sum+rem)%10 + '0';
        rem = (sum+rem)/10;
        i++;
        len1--,len2--;
    }
    for (j=i-1;j>=0;j--) printf("%c",res[j]);
    printf("\n");
    return 0;
}