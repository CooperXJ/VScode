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

int least_common_multiple(int a,int b)
{
    return a*b/max_common_measure(a,b);
}

int main()
{
    cout<<max_common_measure(35,49)<<endl;
    cout<<least_common_multiple(35,49)<<endl;
    system("pause");
}