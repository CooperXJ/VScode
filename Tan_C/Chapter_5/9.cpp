#include <iostream>
#include <math.h>
using namespace std;

int sum_factors(int n)
{
    int res = 0;
    for(int i = 1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            res+=i;
        }
    }
    return res;
}

void f()
{   
    for(int i =1;i<1000;i++)
    {
        if(i==sum_factors(i))
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    f();
    system("pause");
}