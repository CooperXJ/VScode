#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
using namespace std;

#define _USE_MATH_DEFINES
int main()
{
    int r;
    scanf("%d",&r);
    double area = r*r*M_PI;
    cout<<setiosflags(ios::fixed)<<setprecision(7)<<area<<endl;
    system("pause");
}