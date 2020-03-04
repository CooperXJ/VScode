#include <iostream>
#include <math.h>
using namespace std;

/*
    指针常量与常量指针
*/

void show(int *a,int m,int n)
{
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<*(a+i*n+j)<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    // int i = 9;
    // int *p = &i;
    // cout<<*p<<endl;

    //指向常量的指针
    //常量必须要使用常量指针指向它的地址
    // const int i = 1;
    // const int *p = &i;
    // cout<<*p<<endl; 

    //常量指针
    //这个指针本身就是一个常量对象，只能只向同一个对象,但是可以改变指针所指对象的值
    // int i = 1;
    // int *const p = &i;
    // cout<<*p<<endl;
    // //int j  =2;
    // //p = &j;
    // *p = 2;
    // cout<<*p<<endl;

    //auto可以自动确定类型
    // int arr[] = {1,2,3};
    // for(auto i:arr)
    // {
    //     cout<<i<<endl;
    // }

    //arr是数组的指针，这是一个常量，因此不能自增
    // int arr[] = {1,2,3};
    // int *p = arr;
    // //cout<<*arr++<<endl;
    // //但是p可以自增，因为p是常量
    // cout<<*p++<<endl;
    // cout<<*p++<<endl;


    // int a[][2] = {1,2,3,4,5,6};
    // cout<<a<<endl;//指向第一个子数组的指针
    // cout<<a+1<<endl;//指向第二个子数组的指针
    // cout<<&a<<endl;//指向整个二维数组
    // cout<<*a<<endl;//指向a[0]的指针
    // cout<<*a+1<<endl;//指向a[1]的指针

    //由于数组是以指针形式传递给函数的，因此一开始的时候函数并不知道数组的维度。因此有时候有必要显示传递一个维度参数。
    // int a[][2] = {1,2,3,4};
    // int (*p)[2] = a;
    // cout<<p[0][0]<<endl;

    //可以不通过定义指针的维度（*p）[4]来对二维数组进行访问，可以直接找到入口*a,根据指针访问即可
    int a[][2] = {1,2,3,4};
    show(*a,2,2);

    // 永远不要试图返回局部对象的指针。因为局部变量（对象）的生命周期在函数调用结束后会消失，此时你返回的地址的内容可能已经发生了变化。
    // 就比如说在一个函数中定义了一个临时对象，想要返回它的指针这个事不可能的
    system("pause");
}