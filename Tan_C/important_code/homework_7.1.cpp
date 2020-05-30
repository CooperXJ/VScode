#include <iostream>
#include <math.h>
using namespace std;

int max_common_measure(int a,int b)
{
    if(b==0)
        return a;
    else
    {
        int t;
        while(a%b!=0)
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
    cout<<max_common_measure(105,25)<<endl;
    system("pause");
}