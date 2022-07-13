#include<stdio.h>

int main(){
    int time,hour;
    scanf("%d %d",&time,&hour);
    int day = (time + hour)/24;
    time = (time + hour)%24;
    printf("%d %d\n",day,time);
    return 0;
}