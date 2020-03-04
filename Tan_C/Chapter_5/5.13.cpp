#include <iostream>
#include <math.h>
using namespace std;

/*
    1.设定一个x初值x0 = n/2
    2.用公式计算出下一个x1
    3.将x1带入公式右侧的x0，求出下一个x1
    4.如此下去满足关系直到跳出关系
*/
double f(double n)
{
    double x = n/2,X = (x+n/x)*0.5;
    do{
        x = X;
        X = (x+n/x)*0.5;
    }while(fabs(X-x)>1e-5);
    return X;
}

int main()
{
    cout.precision(6);
    cout<<f(2)<<endl;
    system("pause");
}