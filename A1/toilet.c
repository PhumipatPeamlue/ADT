#include<stdio.h>
#include<math.h>

int main(){
    double L_old,L_new,C,N;
    scanf("%lf %lf %lf %lf",&L_new,&L_old,&C,&N);
    double t = ceil(C*1000/(N*(L_old-L_new)));
    printf("%.0lf\n",t);
    return 0;
}