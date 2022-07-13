#include<stdio.h>
int calDay(int y,int m){
    int i;
    int day = 1;
    int month[] = {0,3,0,3,2,3,2,3,3,2,3,2,3};
    for (i=1990;i<y;i++){
        if ((i%4==0&&i%100!=0)||i%400==0){
            day += 2;
            day %= 7;
        }
        else{
            day++;
            day %= 7;
        }
    }
    for (i=1;i<m;i++){
        if (i==2 && (y%4==0&&y%100!=0)||y%400==0){
            day++;
            day %= 7;
        }
        else{
            day += month[i];
            day %= 7;
        }
    }
    return day;
}
void printCalendar(int y,int m){
    int dayStart = calDay(y,m);
    int i,d = 1;
    int day_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 
    char *month[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
    if ((y%4==0&&y%100!=0)||y%400==0) day_month[2] = 29;
    printf("====================\n");
    printf("%s %d\n",month[m],y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (i=0;i<dayStart;i++){
        printf("    ");
    }
    while (d<=day_month[m]){
        printf("%3d ",d);
        d++;
        dayStart++;
        if (dayStart%7==0){
            dayStart = 0;
            printf("\n");
        }
    }
    printf("\n");
}
int main(){
    int y,m;
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);
    printCalendar(y,m);
    return 0;
}