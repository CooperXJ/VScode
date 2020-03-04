#include <iostream>
#include <math.h>
using namespace std;

int Fibonacci(int i)
{
    if(i==1||i==2)
    {
        return 1;
    }
    else
    {
        return Fibonacci(i-1)+Fibonacci(i-2);
    }
    
}

void Fibonacci_For()
{
    int f1 = 1,f2 = 1,f3;
    for(int i =3;i<=40;i++)
    {
        f3 = f1+f2;
        cout<<f3<<endl;
        f1 = f2;
        f2 = f3;
    }
}

int main()
{
    // for(int i =3;i<=40;i++)
    //     cout<<Fibonacci(i)<<endl;
    Fibonacci_For();
    system("pause");
}