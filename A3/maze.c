#include<stdio.h>
int N;
char maze[100][100],ENTER;
int walkCheck[100][100];
int i_way[] = {1,0,-1,0};
int j_way[] = {0,1,0,-1};
int end = 0;
void traverseMaze(int i,int j){
    int k;
    if (maze[i][j]=='G'){
        end = 1;
        return;
    }
    walkCheck[i][j] = 1;
    for (k=0;k<4;k++){
        if (i+i_way[k]<0 || j+j_way[k]<0 || N<=i+i_way[k] || N<=j+j_way[k]) continue;
        if (maze[i+i_way[k]][j+j_way[k]]=='#' || walkCheck[i+i_way[k]][j+j_way[k]]==1) continue;
        traverseMaze(i+i_way[k],j+j_way[k]);
        if (maze[i][j]==' ' && end==1){
            maze[i][j] = '.';
            return;
        }
    }
}
int main(){
    int i,j;
    scanf("%d",&N);
    scanf("%c",&ENTER);
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            scanf("%c",&maze[i][j]);
        }
        scanf("%c",&ENTER);
    }
    int foundS = 0;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            if (maze[i][j]=='S'){
                traverseMaze(i,j);
                foundS = 1;
                break;
            }
        }
        if (foundS==1) break;
    }
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}