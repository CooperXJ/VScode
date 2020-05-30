#include <iostream>
#include <math.h>
using namespace std;

void swap(int *a,int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}

int main()
{
    // int i = 1000;
    // int *add = &i;

    // *add = 88;
    // cout<<*add<<endl;
    // int a = 1;
    // int b = 2;

    // swap(&a,&b);
    // cout<<a<<"   "<<b<<endl;

    // int a[3] = {1,4,5};
    // int *p  = a;
    // swap(a+1,a+2);
    // cout<<*(a+2)<<endl;

    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cout<<a<<endl;
    cout<<a+1<<endl;
    cout<<*(*(a+1))<<endl;//*(a+1)代表的是第1的首地址，**（a+1）代表的是a[1][0]
    cout<<*(*(a+1)+1)<<endl;//*(a+1)代表的是第1的首地址，**（a+1）代表的是a[1][1]
    
    system("pause");
}