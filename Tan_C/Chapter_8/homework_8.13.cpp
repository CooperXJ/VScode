#include <iostream>
#include <math.h>
using namespace std;

/*
    1.确定上下限
    2.确定分割的份数
    3.累加
*/
float fsin(float x)
{
    return sin(x);
}

float fcos(float x)
{
    return cos(x);
}

float fexp(float x)
{
    return exp(x);
}

float intergral(float(*p)(float),float a,float b,int n)
{
    float x = a;
    float s = 0;
    float step = (b-a)/n;
    for(int i = 0;i<n;i++)
    {
        x+=step;
        s+=p(x)*step;
    }

    return s;
}

int main()
{
    float a = 0;
    float b =1;
    cout<<intergral(fsin,a,b,1000)<<endl;
    cout<<intergral(fcos,a,b,1000)<<endl;
    cout<<intergral(fexp,a,b,1000)<<endl;
    system("pause");
}