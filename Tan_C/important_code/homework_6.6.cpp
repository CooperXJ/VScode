#include <iostream>
#include <math.h>
using namespace std;

void f()
{
    int a[10][10] = {0};
    for(int i =0;i<10;i++)
    {
        a[i][0] = 1;
    }

    for(int i = 1;i<10;i++)
    {
        for(int j = 1;j<10;j++)
        {
            a[i][j] = a[i-1][j]+a[i-1][j-1];
        }
    }

    for(int i =0;i<10;i++)
    {
        for(int j = 0;j<=i;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    f();
    system("pause");
}