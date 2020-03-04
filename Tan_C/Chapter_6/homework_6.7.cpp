#include <iostream>
#include <math.h>
using namespace std;

/*
    1.将1放在第一行的最中间
    2.如果x = 0,那么下一个数字x=n-1，y = y++
    3.如果y = n-1,那么下一个数字x--;y = 0
    4.如果x = 0，y = n-1,则下一个数字x++，y不变
    4.如果下一个数字原本的位置已经被填写了，那么和4相同的步骤
*/

void show(int n)
{   
    int **a = (int**)malloc(sizeof(int*)*n);
    for(int i =0;i<n;i++)
    {
        a[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            a[i][j] = 0;
    }

    int val = 2;
    a[0][n/2] = 1;//因为这里是从0开始的因此不需要+1
    //坐标有助于更新
    int x = 0;
    int y = n/2;

    while(val!=n*n+1)
    {
        if(x==0)
        {
            if(y==n-1)//（1，n）
            {   
                a[x+1][y] = val++;
                x++;           
            }
            //除了上面的if中没有嵌套的if else 其他的都需要考虑一下是否该数字被已经被填
            else
            {  
                if(a[n-1][y+1]==0)
                {
                    a[n-1][y+1] = val++;
                    x = n-1;
                    y++;
                }
                else
                {
                    a[x+1][y] = val++;
                    x++;
                }
                    
            }
        }
        else
        {
            if(y==n-1)
            {
                if(a[x-1][0]==0)
                {
                    a[x-1][0] = val++;
                    x--;
                    y = 0;
                }
            }
            else
            {
                if(a[x-1][y+1]==0)
                {
                    a[x-1][y+1] = val++;
                    x--;
                    y++;
                }
                else
                {
                    a[x+1][y] = val++;
                    x++;
                }                
            }            
            
        }
             
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    show(5);
    system("pause");
}