#include <iostream>
#include <math.h>
using namespace std;

int f(int* a,int low,int high,int val)
{
    int mid = (low+high)/2;
    if(a[mid]==val)
    {
        return mid+1;
    }
    
    if(low<high)//这里是递归的出口
    {
        if(a[mid]<val)
        {
            f(a,mid+1,high,val);
        }

        else if(a[mid]>val)
        {
            f(a,low,mid-1,val);
        }
    }
    
    else
    {
        return 0;
    }
    
}

int main()
{
    int a[] = {1,4,6,8,13,15};
    cout<<f(a,0,5,13)<<endl;
    system("pause");
}