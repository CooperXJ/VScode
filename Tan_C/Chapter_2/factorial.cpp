#include <iostream>
#include <math.h>
using namespace std;

int factorial(int j)
{
    int res = 1;
    for(int i = j;i>=1;i--)
    {
        res*=i;
    }
    return res;
}

int main()
{
    cout<<factorial(5)<<endl;
    system("pause");
}