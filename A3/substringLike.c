#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,p,n,i,j,count = 0;
    char *text = NULL,*word = NULL;

    scanf("%d %d %d",&m,&p,&n);
    text = (char*)malloc(sizeof(char)*(m+1));
    word = (char*)malloc(sizeof(char)*(p+1));
    scanf("%s",text);
    scanf("%s",word);
    for (i=0;i<m;i++){
        for (j=i;j<i+p && i+p<=m;j++){
            if (text[j]==word[j-i]) count++;
        }
        if (count>=p-n){
            printf("[");
            for (j=i;j<i+p;j++){
                if (text[j]==word[j-i]) printf("%c",text[j]);
                else printf("?");
            }
            printf("]");
            i += p-1;
        }
        else printf("%c",text[i]);
        count = 0;
    }
    printf("\n");
    return 0;
}