#include<stdio.h>

int main(){
    int num1,num2,ans;
    char op;
    scanf("%d %c %d",&num1,&op,&num2);
    switch (op){
        case('+'):
            printf("%d\n",num1+num2);
            break;
        case('-'):
            printf("%d\n",num1-num2);
            break;
        case('*'):
            printf("%d\n",num1*num2);
            break;
        case('/'):
            printf("%.2f\n",(float)num1/num2);
            break;
        case('%'):
            printf("%d\n",num1%num2);
            break;
        default:
            printf("Unknown Operator\n");
            break;
    }
    return 0;
}