#include <iostream>
#include <math.h>
using namespace std;

int f(int a,int b)
{
    int m = 1;
    int n = 1;
    if(a==b)
    {
        return 1;
    }
    
    while(b>=a)
    {
        m*=b%998244353;
        b--;
    }
    while(a)
    {
        n*=a%998244353;
        a--;
    }
    
    return m/n;
}

int main()
{
    long long  int sum = 0;
    int n;
    cin>>n;

    int n1 = n - 1;
    long long int x = 1;
    while(n1)
    {
        x*=2;
        x = x%998244353;
        n1--;
    }

    sum = (n*x)%998244353 - n;
   
    cout<<sum%998244353<<endl;
    system("pause");
}
