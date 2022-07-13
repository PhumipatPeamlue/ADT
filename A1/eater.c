#include<stdio.h>
#include<math.h>
int main(){
    double x,y,z;
    char c1,c2;
    scanf("%lf %lf %lf",&x,&y,&z);
    scanf(" %c %c",&c1,&c2);
    if (c1=='Y' || c1=='y') x = x+y;
    if (c2=='Y' || c2=='y') x = ceil(x/z);
    printf("%.0lf\n",x);
    return 0;
}