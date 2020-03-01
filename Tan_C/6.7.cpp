#include <iostream>
#include <math.h>
#include <malloc.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int **arr = (int**)malloc(sizeof(int*)*n);
    for(int i =0;i<n;i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

    arr[0][n/2] = 1;
    
    int **arr_flag = (int**)malloc(sizeof(int*)*n);
    for(int i =0;i<n;i++)
    {
        arr_flag[i] = (int*)malloc(sizeof(int)*n);
    }

    
    for(int i =0;i<n;i++)
    {
         for(int j =0;j<n;j++)
         {
             arr_flag[i][j] = 0;
         }
    }


    arr_flag[0][n/2] = 1; 

    int k = 1;
    while(k!=n*n)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(arr[i][j]==k&&(k+1)<=n*n)
                {
                    if(i==0)
                    {
                        if(j==n-1&&arr_flag[i+1][j]==0)
                        {
                            arr[i+1][j]=++k;
                            arr_flag[i+1][j] = 1;
                        }
                        else if(arr_flag[n-1][j+1]==0)
                        {
                             arr[n-1][j+1] = ++k;
                             arr_flag[n-1][j+1] = 1;
                        }
                        else
                        {
                            arr[i-1][j] = ++k;
                            arr_flag[i-1][j] = 1;
                        }
                        
                    }

                    else if(j==n-1&&(k+1)<=n*n)
                    {
                        if(arr_flag[i-1][0]==0)
                        {
                            arr[i-1][0] = ++k;
                            arr_flag[i-1][0] = 1;
                        }
                        else
                        {
                            arr[i-1][j] = ++k;
                            arr_flag[i-1][j] = 1;
                        }
                        
                        
                    }

                    else if((k+1)<=n*n)
                    {
                        if(arr_flag[i-1][j+1]==0)
                        {
                            arr[i-1][j+1] = ++k;
                            arr_flag[i-1][j+1] = 1;
                        }
                        else
                        {
                            arr[i+1][j] = ++k;
                            arr_flag[i+1][j] = 1;
                        }                        
                    }
                }
            }
        }
    }

    for(int i =0;i<n;i++)
    {
         for(int j =0;j<n;j++)
         {
             cout<<arr[i][j]<<" ";
         }
         cout<<endl;
    }

    system("pause");
}