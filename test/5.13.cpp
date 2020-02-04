#include <iostream>
#include <math.h>
using namespace std;

double sub(double x,double a)
{
    return (x+a/x)/2;
}

int main()
{
    double a = 5;
    double x0 = a/2;
    double x1 = sub(x0,a);

    while(fabs(x0-x1)>1e-5)
    {
        x0 = x1;
        x1 = sub(x1,a);
    }

    cout<<x1<<endl;
    system("pause");
}