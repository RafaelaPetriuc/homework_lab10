#include <stdio.h>

void labyrinth(int n, int m, int x, int y, int a[50][50], int exit,int *ok)
{
    if(ok) {
        for (int i = 0; i <= n; i++) a[0][i] = -1;
        for (int i = 0; i <= m; i++) a[i][0] = -1;
        for (int i = 0; i <= n; i++) a[n + 1][i] = -1;
        for (int i = 0; i <= m; i++) a[i][m + 1] = -1;
        *ok=0;
    }

    if(a[x][y]==1)
    {
        printf("%d %d \n",x,y);
        a[x][y]=2;
        if((a[x-1][y]==-1) || (a[x+1][y]==-1) || (a[x][y-1]==-1) || (a[x][y+1]==-1)){
            printf("Exit point is : %d %d \n",x,y);
        }
        else
        {
            labyrinth(n,m,x,y-1,a,exit,ok);
            labyrinth(n,m,x,y+1,a,exit,ok);
            labyrinth(n,m,x-1,y,a,exit,ok);
            labyrinth(n,m,x+1,y,a,exit,ok);
        }
        a[x][y]=1;
    }

}

int main() {
    int n=0,m=0,x=0,y=0,exit=0,a[50][50],ok=1;
    printf("Please input starting coordinates : \n");
    scanf("%d%d",&x,&y);
    printf("Please input size of the maze and it's elements : \n");
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1 ; j<=m;j++)
            scanf("%d",&a[i][j]);

    labyrinth(n,m,x,y,a,exit,&ok);

    for(int i=1;i<=n;i++,printf("\n"))
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);

    return 0;
}