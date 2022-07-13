#include<stdio.h>

int checkYear(int y){
    if ((y%4==0 && y%100!=0) || y%400==0) return 1;
    else return 0;
}

int m_to_d (int m,int y){
    int tmp[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m==2 && checkYear(y)) return 29;
    else return tmp[m];
}

int main(){
    int d,m,y,i;
    scanf("%d/%d/%d",&d,&m,&y);
    for (i=1;i<m;i++){
        d += m_to_d(i,y);
    }
    printf("%d\n",d);
    return 0;
}