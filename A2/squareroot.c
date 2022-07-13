#include<stdio.h>
#include<math.h>

int main(){
    double N,before_G,after_G;
    scanf("%lf %lf",&N,&before_G);
    while (1){
        after_G = 0.5*(before_G + N/before_G);
        if (fabs(before_G-after_G)<1E-10){
            printf("%.10lf %.10lf %.10lf\n",after_G,before_G,fabs(before_G-after_G));
            printf("%.10lf\n",after_G);
            break;
        }
        else{
            printf("%.10lf %.10lf %.10lf\n",after_G,before_G,fabs(before_G-after_G));
            before_G = after_G;
        }
    }
    return 0;
}