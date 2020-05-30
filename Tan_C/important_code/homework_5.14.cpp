#include <iostream>
#include <math.h>
using namespace std;

double f()
{
    double x0 = 1.5;
    double f = 2*pow(x0,3)-4*pow(x0,2)+3*x0 - 6;
    double f1 = 6*pow(x0,2)-8*x0+3;
    double x1 = x0 - f/f1;
    
    while (fabs(x0-x1)>=1e-5)
    {
        x0 = x1;
        f = 2*pow(x0,3)-4*pow(x0,2)+3*x0 - 6;
        f1 = 6*pow(x0,2)-8*x0+3;
        x1 = x0 - f/f1;
    }
    
    return x1;
}

double f1()
{
    double x0,x1,f,f1;
    x1 = 1.5;

    do{
        x0 = x1;
        f = 2*pow(x0,3)-4*pow(x0,2)+3*x0 - 6;
        f1 = 6*pow(x0,2)-8*x0+3;
        x1 = x0 - f/f1;
    }while(fabs(x0-x1)>=1e-5);
    return x1;
}

int main()
{
    cout<<f()<<endl;
    cout<<f()<<endl;
    system("pause");
}