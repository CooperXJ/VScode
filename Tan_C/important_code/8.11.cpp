#include <iostream>
#include <math.h>
using namespace std;

void show(int (*p)[4])
{
    for(int i = 0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

void f(int *a)
{
    for(int i =0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
            cout<<*(a+i*4+j)<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    // int (*p)[4] = a;
    // int *p1 = a[0];
    // cout<<a<<endl;//第一行起始地址
    // cout<<a[0]<<endl;//第一行第一个的地址

    // cout<<*(*a+1)<<endl;//第一行第2个值
    // cout<<*(a+1)<<endl;//第二行的行地址
    // cout<<a[1]<<endl;//第二行第一个的首地址

    // int (*p)[4] = &a[0];//p是第一行的首地址
    // int (*p1)[4] = a;//p1和p一样
    // cout<<&a[0]<<endl;
    // cout<<a<<endl;

    // int *p = &a[0][1];
    // int *p1 = *(a)+1;
    // cout<<&a[0][1]<<endl;
    // cout<<*(a)+1<<endl;

    show(a);
    f(*a);//当作一维数组来处理
    system("pause");
}