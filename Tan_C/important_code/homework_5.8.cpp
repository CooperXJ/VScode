#include <iostream>
#include <math.h>
using namespace std;

void f()
{
    for(int i =100;i<1000;i++)
    {
        int ge = i%10;
        int shi = (i/10)%10;
        int bai = i/100;

        if((pow(ge,3)+pow(shi,3)+pow(bai,3))==i)
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    f();
    system("pause");
}