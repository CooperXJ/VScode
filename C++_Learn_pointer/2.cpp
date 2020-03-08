#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int arr[][2] ={1,2,3,4,5,6};
    for(int i =0;i<3;i++)
    {
        for(int j = 0;j<2;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    /*
    我想说明的一点就是二维数组中的数组名是指向一个一维数组的指针，相当于是行指针，一行一行的指
    例如arr[3][2],那么arr就是一个指向arr[0][0]-arr[0][1]的指针
    *(arr)也就是取arr[0][0]的首地址，即arr[0]的值
    arr+1指向的是第二行的首地址，*（arr+1）等价于arr[1]的值，也就是arr+1
    总结：
    arr+i是指向行的指针，arr[i]是指向一维数组首地址的指针
    array 是二维数组的名字，它指向的是所属元素的首地址，其每个元素为一个行数组。它是以‘行’来作为指针移动单位的，
    如array+i 指向的是第 i 行。对 array 进行 * 运算，得到的是一维数组 array[0] 的首地址，所以 *array 与 array[0] 为同个值。
    如果定义 int* p，p为指int类型的指针，指向int 类型，而不是地址。故以下操作 ：p=array[0] (正确) ，p=array (错误) 。
    */
    system("pause");
}