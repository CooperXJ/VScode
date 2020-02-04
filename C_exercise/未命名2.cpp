#include <stdio.h>
#define M 3
#define N 4
void Input(int *p, int m, int n);       //1
int FindMax(int *p, int m, int n, int *pRow, int *pCol);            //1
 
main()
{                         
    int score[M][N], maxScore, row, col;
    printf("Please input your data:\n");
    Input(*score, M, N);            //1
    maxScore = FindMax(*score, M, N, &row, &col);           //2
    printf("The maximum is %d, which is in row %d, colum %d\n", maxScore, row, col);
}                         
 
void Input(int *p, int m, int n)
{                         
    int i, j;
    for (i = 0; i < m; i++)     //1
    {                         
        for (j = 0; j < n; j++)     //1
            scanf("%d", &p[i * n + j]);
    }
}                         
 
int FindMax(int *p, int m, int n, int *pRow, int *pCol )
{                         
    int  i, j, max;
    max = p[0];     //1
    *pRow = 0;
    *pCol = 0;
    for ( i = 0; i < m; i++ )       //1
    {                         
        for ( j = 0; j < n; j++ )           //1
        {                         
            if ( p[ i * n + j ] > max )         //1
            {                         
                max = p[ i * n + j];            //1
                *pRow = i;
                *pCol = j;
            }
        }
    }
    return max;
}  
