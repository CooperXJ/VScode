#include <iostream>
#include <math.h>
using namespace std;

void solve_equation(float a,float b,float c)
{
    cout.precision(4);
    if(a==0)//a=0也需要考虑进来
    {
        cout<<"x = "<<c/b<<endl;
    }

    else
    {
         float t = b*b - 4*a*c;
        if(t<0)
        {
            cout<<"no solution of equation"<<endl;
        }
        else if(t==0)
        {
            t = sqrt(t);      
            cout<<"x1,x2 = "<<(-b)/(2*a)<<endl;
        }
        else
        {
            t = sqrt(t);
            cout<<"x1 = "<<(-b+t)/(2*a)<<endl;
            cout<<"x2 = "<<(-b-t)/(2*a)<<endl;
        }
    }
        
}

int main()
{
    solve_equation(1,-6,2);
    system("pause");
}