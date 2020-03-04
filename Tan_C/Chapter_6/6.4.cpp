#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

int ** transofrm(int (*a)[3])
{
    //这里必须分配内存，因为如果不分配内存的话，函数执行完之后就会自动释放掉
    //原来定义数组的内存，但是自己开辟的内存需要自己进行释放
    //比如这里如果我写成int b[3][2] = {0},这样只会临时开辟内存，一旦函数结束就会释放掉，从而指针b无法
    //就会消失，但是可以通过声明变量为static来保留着内存
    int **b = (int**)malloc(sizeof(int*)*3);
    for(int i =0;i<3;i++)
    {
        b[i] = (int*)malloc(sizeof(int)*2);
    }

    for(int i =0;i<2;i++)
    {
        for(int j =0;j<3;j++)
        {
            b[j][i] = a[i][j];
        }
    }
    return b;
}

int main()
{
    int b[][3] = {1,2,3,4,5,6};
    int **a = transofrm(b);
    for(int i =0;i<3;i++)
    {
        for(int j =0;j<2;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
}