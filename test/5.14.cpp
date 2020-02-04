#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x1,x0;
    x1 = 1.5;

    do
    {
        x0 = x1;
        double f = 2*pow(x0,3) - 4*pow(x0,2)+3*x0-6;
        double f1 = 6*pow(x0,2) - 8*x0+3;
        x1 = x0 - f/f1;
    } while (fabs(x1-x0)>1e-5);
    
    cout<<x1<<endl;
    system("pause");
}