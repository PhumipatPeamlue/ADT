#include<stdio.h>

void Roman(int num){
    int i;
    while (num>0){
        if (num>=1000){
            for (i=0;i<num/1000;i++){
                printf("M");
            }
            num -= (num/1000)*1000;
        }
        else if (num>=100){
            if (num/100<4){
                for (i=0;i<num/100;i++){
                    printf("C");
                }
            }
            else if (num/100==4) printf("CD");
            else if (num/100<9){
                printf("D");
                for (i=5;i<num/100;i++){
                    printf("C");
                }
            }
            else if (num/100==9) printf("CM");
            num -= (num/100)*100;
        }
        else if (num>=10){
            if (num/10<4){
                for (i=0;i<num/10;i++){
                    printf("X");
                }
            }
            else if (num/10==4) printf("XL");
            else if (num/10<9){
                printf("L");
                for (i=5;i<num/10;i++){
                    printf("X");
                }
            }
            else if (num/10==9) printf("XC");
            num -= (num/10)*10;
        }
        else{
            if (num<4){
                for (i=0;i<num;i++){
                    printf("I");
                }
            }
            else if (num==4) printf("IV");
            else if (num<9){
                printf("V");
                for (i=5;i<num;i++){
                    printf("I");
                }
            }
            else if (num==9) printf("IX");
            num = 0;
        }
    }
    printf("\n");
}

int main(){
    int n;
    int num;
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&num);
        Roman(num);

    }
    return 0;
}