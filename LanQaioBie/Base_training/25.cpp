#include <iostream>
#include <malloc.h>
using namespace std;

int k =0;
void read(int *res,int m,int n,int **arr,int **arr1)
{
    for(int i =0;i<m;i++)
    {
        res[k++] = arr[i][0];
        arr1[i][0] = 0;
    }

    for(int i = 0;i<n;i++)
    {
        res[k++] = arr[m][i];
    }

    for(int i =m;i>=0;i--)
    {
        res[k++] = arr[i][n];
    }

    for(int i =n;i>=0;i--)
    {
        res[k++] = arr[0][i];
    }
}
int main()
{
    int m,n;
    cin>>m>>n;

    int **arr = (int**)malloc(sizeof(int*)*m);
    for(int i =0;i<m;i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

     for(int i =0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int **arr1 = (int**)malloc(sizeof(int*)*m);
    for(int i =0;i<m;i++)
    {
        arr1[i] = (int*)malloc(sizeof(int)*n);
    }
    
    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            arr1[i][j] = 1;
        }
    }

    int *res = (int*)malloc(sizeof(int)*m*n);
   
  
}