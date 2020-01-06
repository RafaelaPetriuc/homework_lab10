#include<stdio.h>
#define N 8
int sol[N][N];
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void solve(int x, int y, int move);

int isSafe(int x, int y)
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == 0);
}

void printSolution()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
    printf("\n\n");
}


void solve(int x, int y, int move)
{
    int k, next_x, next_y;
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y))
        {
            sol[next_x][next_y] = move;
            if (move == N*N){
                printSolution();
            }
            solve(next_x, next_y, move+1);
            sol[next_x][next_y] = 0;
        }
    }
}

int main()
{
    solve( 0, 0, 0);
    printSolution();
    return 0;
}