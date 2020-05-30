#include <iostream>
#include <math.h>
using namespace std;

void binary(int a[])
{
    int res = 0;
   
    for(int i =0;i<4;i++)
    {
        res = res*2+a[i];
    }

    cout<<"res = "<<res<<endl;
}

void to_binary(int a)
{
    int arr[100];
    int i = 0;
    while(a!=0)
    {
        a = a%2;
        arr[i++] = a;
        a/=2;
    }

    for(int j = i-1;j>=0;j--)
    {
        cout<<arr[j];
    }

    cout<<endl;
}

int main()
{
    int a[] = {1,1,1,0};
    binary(a);
    to_binary(3);
    system("pause");
}