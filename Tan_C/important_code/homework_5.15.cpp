#include <iostream>
#include <math.h>
using namespace std;

double f()
{
    double x0 = -10,x1 = 10,f0,f1;
    double x,f;
    do{
        f0 = 2*pow(x0,3)-4*pow(x0,2)+3*x0 - 6;
        f1 = 2*pow(x1,3)-4*pow(x1,2)+3*x1 - 6;
        
        x = (x0+x1)/2;
        f = 2*pow(x,3)-4*pow(x,2)+3*x - 6;
        if(f0*f<0)
        {
            x1 = x;
        }

        else
        {
            x0 = x;
        }

    }while(fabs(f)>=1e-5);//这里需要注意下，不是fabs(x)>=1e-5  而是f,因为只有当f与与0比较接近时才能将其看作是原方程的解

    return x;
}

int main()
{
    cout<<f()<<endl;
    system("pause");
}