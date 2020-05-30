#include <iostream>
#include <math.h>
using namespace std;

void f(int *a,int count,int n)
{
    int arr[3] = {0};

    for(int i =0;i<count;i++)
    {
        int pos = (i+n)%count;
        arr[pos] = a[i];
    }

    for(int i =0;i<count;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[3] = {1,2,3};
    f(a,3,2);
    system("pause");
}