#include <iostream>
#include <math.h>
using namespace std;

void change(int *arr)
{
    arr[2] = 4;
}

int main()
{
    //将数组变量改变是可以进行数组元素的重新赋值的
    // int a[] = {1,2,3};
    // for(auto i :a)
    //     cout<<i<<" ";
    // cout<<endl;
    // change(a);
    // for(auto i :a)
    //     cout<<i<<" ";
    // cout<<endl;
    
    //int arr[][3] = {1,2,3,4,5,6,7,8,9};
    // int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // cout<<a[1]<<endl;
    // cout<<&(a[1][0])<<endl;
    // cout<<*arr<<endl;
    // cout<<*(arr+1)<<endl;
    // cout<<arr+1<<endl;
    // cout<<*(*arr)<<endl;
    // cout<<*(*(arr+1)+1)<<endl;

    // char a[] = "123";
    // a[4] = "234";
    // cout<<a<<endl;

    int a[8] = {1,2,3,4,5,6,7,8};

    int i = 0,j = 0,len = 8;
    while (len!=1)
    {
       if(a[i]!=0)
         j++;
        
        if(j==3)
        {
            a[i] = 0;
            j = 0;
            len--;
        }

        i++;

        if(i==8)
            i = 0;
    }
    
    for(auto i :a)
    {
        if(i!=0)
            cout<<i<<endl;
    }

    system("pause");
}