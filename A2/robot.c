#include<stdio.h>
#include<math.h>

int main(){
    int N,i;
    int angle = 0,x = 0,y = 0;
    float dis;
    char cmd;
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf(" %c",&cmd);
        if (cmd=='L'){
            angle -= 90;
            if (angle<0) angle = 270;
        }
        else if (cmd=='R'){
            angle += 90;
            if (angle==360) angle = 0;
        }
        else if (cmd=='F'){
            if (angle==0) x++;
            else if (angle==90) y--;
            else if (angle==180) x--;
            else if (angle==270) y++;
        }
    }
    dis = sqrtf(x*x+y*y);
    printf("%.4f\n",dis);
    return 0;
}