#include<stdio.h>
#include<math.h>
int checkPrime(int n){
    if (n <= 1) return 0;
    else{
        int i,N = sqrt(n)+1;
        for (i=2;i<N;i++){
            if (n%i == 0) return 0;
        }
    }
    return 1;
}
int main(){
    int n,isPrime = 1;
    scanf("%d",&n);
    isPrime = checkPrime(n);
    if (isPrime) printf("1\n");
    else printf("0\n");
    return 0;
}
//complexity is O(sqrt(n))