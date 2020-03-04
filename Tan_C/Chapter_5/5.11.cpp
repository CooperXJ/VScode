#include <iostream>
#include <math.h>
using namespace std;

double height(int count)
{
    double sn = 100;
    double hn = sn/2;
    for(int i =1;i<count;i++)
    {
        sn+=2*hn;
        hn/=2;
    }
    cout<<sn<<endl;
    return hn;
}

int main()
{
    cout<<height(10)<<endl;
    system("pause");
}