#include <iostream>
#include <math.h>
using namespace std;

double f(double a)
{
    double x0 = a/2;//此处x0的初始值最好选择a/2,这样更具有鲁棒性
    double x1 = (x0+a/x0)*0.5;

    while (fabs(x0-x1)>=1e-5)
    {
        x0 = x1;
        x1 = (x0+a/x0)*0.5;
    }

    return x1;
}

int main()
{
    cout<<f(2)<<endl;
    system("pause");
}