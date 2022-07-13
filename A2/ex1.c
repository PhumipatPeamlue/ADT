#include<stdio.h>

int main(){
    int money;

    scanf("%d",&money);
    for (int i=0;i<10;i++){
        money += 0.05*money;
    }
    printf("%d\n",money);
    return 0;
}