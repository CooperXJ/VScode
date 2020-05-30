#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

void f(int n)
{
    int **a = (int**)malloc(sizeof(int*)*n);
    for(int i =0;i<n;i++)
    {
        a[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            a[i][j] = 0;
        }
    }

    //第一行最中间一个为1
    a[0][n/2] = 1;
    int x = 0;
    int y =n/2;

    int len = 1;
    while(len!=n*n)
    {
        if(x==0)
        {
            if(a[n-1][y+1]==0)
            {
                a[n-1][y+1] = ++len;
                x = n-1;
                y = y+1;
            }
            else 
            {
                a[x+1][y] = ++len;
                x = x+1;
                y = y;
            }
        }
        else if(y==n-1)
        {
            if(a[x-1][0]==0)
            {
                a[x-1][0] = ++len;
                x = x-1;
                y = 0;
            }
            else
            {
                a[x+1][y] = ++len;
                x = x+1;
                y = y;
            }            
        }
        else
        {
            if(a[x-1][y+1]==0)
            {
                a[x-1][y+1] = ++len;
                x = x-1;
                y = y+1;
            }
            else
            {
                a[x+1][y] = ++len;
                x = x+1;
                y = y;
            } 
        }
              
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    f(5);
    system("pause");
}