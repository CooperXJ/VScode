#include <iostream>
#include <math.h>
using namespace std;

int Factorial(int n)
{
    int res = 1;
    for(int i = n;i>=1;i--)
    {
        res*=i;
    }
    return res;
}

int main()
{
    int res = 0;
    for(int i =1;i<=20;i++)
    {
        res+=Factorial(i);
    }
    cout<<res<<endl;
    system("pause");
}