#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len1,len2;
int char_to_int(char c){return c-48;}
char int_to_char(int n){return n+48;}
void getBigNum(char **num1,char **num2){
    char tmp1[1001],tmp2[1001];
    scanf("%s",tmp1);
    scanf("%s",tmp2);
    int i,j;
    len1 = strlen(tmp1),len2 = strlen(tmp2);
    *num1 = (char *)malloc(sizeof(char)*(len1+1));
    *num2 = (char *)malloc(sizeof(char)*(len2+1));
    for (i=0;i<len1;i++){
        *(*num1+i) = *(tmp1+len1-1-i);
    }
    for (i=0;i<len2;i++){
        *(*num2+i) = *(tmp2+len2-1-i);
    }
}
void plus(char **num1,char **num2,char **res){
    int i,j,tod = 0;
    if (len1>len2){
        *res = (char *)malloc(sizeof(char)*len1+2);
        for (i=0;i<len2;i++){
            if (char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod > 9){
                *(*res+i) = int_to_char((char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod)%10);
                tod = 1;
            }
            else{
                *(*res+i) = int_to_char(char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod);
                tod = 0;
            }
        }
        for (i=len2;i<len1;i++){
            if (char_to_int(*(*num1+i)) + tod > 9){
                *(*res+i) = int_to_char((char_to_int(*(*num1+i)) + tod)%10);
                tod = 1;
            }
            else{
                *(*res+i) = int_to_char(char_to_int(*(*num1+i)) + tod);
                tod = 0;
            }
        }
        if (tod==1) *(*res+len1) = '1';
        for (j=len1;j>=0;j--){
            printf("%c",*(*res+j));
        }
        printf("\n");
    }
    else if (len1<len2){
        *res = (char *)malloc(sizeof(char)*len2+2);
        for (i=0;i<len1;i++){
            if (char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod > 9){
                *(*res+i) = int_to_char((char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod)%10);
                tod = 1;
            }
            else{
                *(*res+i) = int_to_char(char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod);
                tod = 0;
            }
        }
        for (i=len1;i<len2;i++){
            if (char_to_int(*(*num2+i)) + tod > 9){
                *(*res+i) = int_to_char((char_to_int(*(*num2+i)) + tod)%10);
                tod = 1;
            }
            else{
                *(*res+i) = int_to_char(char_to_int(*(*num2+i)) + tod);
                tod = 0;
            }
        }
        if (tod==1) *(*res+len2) = '1';
        for (j=len2;j>=0;j--){
            printf("%c",*(*res+j));
        }
        printf("\n");
    }
    else{
        *res = (char *)malloc(sizeof(char)*len1+2);
        for (i=0;i<len2;i++){
            if (char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod > 9){
                *(*res+i) = int_to_char((char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod)%10);
                tod = 1;
            }
            else{
                *(*res+i) = int_to_char(char_to_int(*(*num1+i)) + char_to_int(*(*num2+i)) + tod);
                tod = 0;
            }
        }
        if (tod==1) *(*res+len2) = '1';
        for (j=len1;j>=0;j--){
            printf("%c",*(*res+j));
        }
        printf("\n");
    }
}
int main(){
    char *num1 = NULL,*num2 = NULL,*res = NULL;
    getBigNum(&num1,&num2);
    plus(&num1,&num2,&res);
    return 0;
}