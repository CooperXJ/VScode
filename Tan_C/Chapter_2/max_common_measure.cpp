#include <iostream>
#include <math.h>
using namespace std;

int max_common_measure(int a,int b)
{
    if(a>b)
    {
        while(a%b!=0)
        {
            int t = a%b;
            a = b;
            b = t;
        }

        return b;
    }
    else
    {
        return a;
    }
    
}

int main()
{
    cout<<max_common_measure(108,40)<<endl;
    system("pause");
}