#include <iostream>
#include <math.h>
using namespace std;

int max_common_measure(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        int t;
        while (a%b!=0)
        {
           t = a%b;
           a = b;
           b = t;
        }
        return t;
    }
}


int main()
{
    int a = 104,b = 24;
    cout<<max_common_measure(104,24)<<endl;
    cout<<a*b/max_common_measure(a,b)<<endl;
    system("pause");
}