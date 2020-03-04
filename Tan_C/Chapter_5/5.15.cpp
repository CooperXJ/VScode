#include <iostream>
#include <math.h>
using namespace std;

/*
    1.输入x1和x2的值  找到满足f(x1)与f(x0)异号
    2.找到x1和x0的中间点
    3.计算f(x0)和f(x1)是否异号，如果异号则将x2更新为x0   如果同号，则将x1更新为x0
    4.如果f0<e-5 那么就输出 跳出循环
*/
void f()
{
    double x1 ;
    double x2 ;
    double f0,f1,f2;
    double x0;
    do{
        cin>>x1>>x2;
        f1 = 2*pow(x1,3)-4*pow(x1,2)+3*x1-6;
        f2 = 2*pow(x2,3)-4*pow(x2,2)+3*x2-6;
        
    }while(f1*f2>0);

    do
    {
        x0 = (x1+x2)/2;
        f0 = 2*pow(x0,3)-4*pow(x0,2)+3*x0-6;
        if(f0*f1<0)//这里必须要f0和f1  因为只有f0和f1异号的时候就将X2 = x0,因为X0和X对应的值是同号的，那么X比X2距离真正的根更近
        {
            x2 = x0;
            f2 = f0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }    
    } while (fabs(f0)>=1e-5);
    
    cout<<x0<<endl;
}

int main()
{
    f();
    system("pause");
}