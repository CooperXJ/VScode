#include <iostream>
#include <math.h>
using namespace std;

/*
    1.确定一个合理的x0
    2.求出x0带入的f(X0)与f'(x0)
    3.x1 = x0-f(x0)/f'(x0)
    4.循环直到满足条件跳出循环
*/

double f()
{
    double x0;
    double f,f1,x1;
    x1 = 1.5;

    do{
    x0 = x1;
    f = 2*pow(x0,3)-4*pow(x0,2)+3*x0-6;
    f1 = 6*pow(x0,2)-8*x0+3;
    x1 = x0 - f/f1;
    }while (fabs(x1-x0)>1e-5);
    return x1;
}

int main()
{
    cout.precision(3);
    cout<<f()<<endl;
    system("pause");
}