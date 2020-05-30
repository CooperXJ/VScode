#include <iostream>
#include <math.h>
using namespace std;

void Fun(int a[],int n)
{
    int i,t;
    for(i=0;i<n/2;i++)
    {
        t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}

int main()
{
    int i,b[8] = {1,2,3,4,5,6,7,8};
    Fun(b+2,6);
    for(i=0;i<8;i++)
        cout<<b[i]<<" ";//1 2 8 7 6 5 4 3
    cout<<endl;

    system("pause");
}