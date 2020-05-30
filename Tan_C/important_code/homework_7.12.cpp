#include <iostream>
#include <math.h>
using namespace std;

double f(int a,int b,int c,int d)
{
    double x0;
    double x1 = 1,f0,f1;
    do{
        x0 = x1;
        f0 = a*pow(x0,3)+b*pow(x0,2)+c*x0+d;
        f1 = 2*a*pow(x0,2)+b*x0+c;
        x1 = x0 - f0/f1;
    }while(fabs(x0-x1)>1e-5);
    return x1;
}

int main()
{
    cout<<f(1,2,3,4)<<endl;
    system("pause");
}