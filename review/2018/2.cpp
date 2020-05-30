#include <iostream>
#include <math.h>
using namespace std;

int f(int a,int b)
{
    if(b==0)
        return a;
    
    while(b!=0)
    {
        int t = a%b;
        a = b;
        b = t;
    }

    return a;
}

int main()
{
    int a = 12,b = 16;
    cout<<f(a,b)<<endl;
    cout<<f(35,28)<<endl;
    system("pause");
}