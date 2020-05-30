#include <iostream>
#include <math.h>
using namespace std;

int f(int base_number,int count)
{
    int res = 0;
    for(int i =0;i<count;i++)
    {
        float t = 0;
        for(int j = 0;j<=i;j++)
        {
            t+=pow(10,j)*base_number;
        }
        res+=t;
    }
    return res;
}

int main()
{
    cout<<f(2,5)<<endl;
    system("pause");
}