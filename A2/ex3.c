#include<stdio.h>

int main(){
    int c;

    printf("Enter a message: ");
    while (1){
        c = getchar();
        if (c=='\n'){
            printf("\n");
            break;
        }
        else if (97<=c && c<=122) printf("%c",c-'a'+'A');
        else printf("%c",c);
    }
    return 0;
}