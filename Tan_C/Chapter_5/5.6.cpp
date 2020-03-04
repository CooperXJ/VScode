#include <iostream>
#include <math.h>
using namespace std;

void Matrix()
{
    for(int i =1;i<=4;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cout<<i*j<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    Matrix();
    system("pause");
}