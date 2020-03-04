#include <iostream>
#include <math.h>
using namespace std;


double sum()
{
    double a = 2,b = 1,res = 0;
    for(int i = 0;i<20;i++)
    {
        res+=a/b;
        double t = a;
        a = a+b;
        b = t;
    }
    return res;
}

int main()
{
    cout<<sum()<<endl;
    system("pause");
}