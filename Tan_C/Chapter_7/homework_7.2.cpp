#include <iostream>
#include <math.h>
using namespace std;

double f(double x,double a,double b,double c,double d)
{
    double f,f1,x0,x1;
    x1 =x;
    do
    {
        x0 = x1;
        f = a*pow(x0,3)+b*pow(x0,2)+c*x0+d;
        f1 = a*3*pow(x0,2)+2*b*x0+c;
        x1 = x0 - f/f1;
    } while (fabs(x1-x0)>1e-5);
    return x1;   
}

int main()
{
    cout.precision(6);
    cout<<f(1,1,2,3,4)<<endl;
    system("pause");
}