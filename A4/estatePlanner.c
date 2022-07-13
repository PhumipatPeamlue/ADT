#include<stdio.h>
#include<math.h>
int count = 0;
void Planner(int a,int b,int n){
    int tmp;
    if (a==0 || b==0) return;
    if (a>b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while (1){
        if ((int)pow(2,n)<=a && (int)pow(2,n)<=b) break;
        n--;
    }
    if (a-(int)pow(2,n)==0){
        if (a*b==(int)pow(2,2*n)){
            count++;
            return;
        }
        count++;
        Planner(a,b-(int)pow(2,n),n);
    }
    else{
        count++;
        Planner(a-(int)pow(2,n),b,n);
        Planner(b-(int)pow(2,n),(int)pow(2,n),n);
    }
}
int main(){
    int a,b,n = 0;
    
    scanf("%d %d",&a,&b);
    while (1){
        if ((int)pow(2,n+1)>a || (int)pow(2,n+1)>b) break;
        n++;
    }
    Planner(a,b,n);
    printf("%d\n",count);
    return 0;
}
//complexity is Polynomial (O(n**k)).