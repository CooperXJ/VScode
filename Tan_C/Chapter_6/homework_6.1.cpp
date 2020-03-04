#include <iostream>
#include <math.h>
using namespace std;

/*
    挑选100以内的素数
    思路：
    1.将1挖去，因为1不是素数
    2.用2除以它后面的各个数字，将2的倍数挖去
    3.将3的倍数挖去
    4.然后挖去4，5，....的倍数，知道√n（这里不需要到n，只要到√n）
    5.一直进到所有的非素数都被挖去
*/

int main()
{
    int a[101];
    for(int i =1;i<=100;i++)
    {
        a[i] = i; 
    }

    a[1] = 0;//因为1是素数
    for(int i =2;i<sqrt(100);i++)
    {
        for(int j = i+1;j<=100;j++)
        {
            if(a[i]!=0&&a[j]!=0)
            {
                if(a[j]%a[i]==0)
                {
                    a[j]=0;
                }
            }
        }
    }

    for(auto i :a)
    {
        if(i!=0)
            cout<<i<<endl;
        else
        {
            continue;
        }
        
    }
    system("pause");
}