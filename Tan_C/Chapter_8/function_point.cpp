#include <iostream>
#include <math.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

void swap(int a,int b)
{
    int t = a;
    b = a;
    a = t;
}

int main()
{
    //int (*p)(int,int);
    // p = max;
    // cout<<p(1,2)<<endl;
    void (*q)(int,int);

    q = swap;
    int a = 1;
    int b = 2;
    q(a,b);
    cout<<a<<" "<<b<<endl;
    system("pause");
}