#include <iostream>
#include <math.h>
using namespace std;

void f()
{
    for(int i =1,k = 3;i<=7,k>=0;i+=2,k--)
    {
        for(int l = 0;l<k;l++)
        {
            cout<<" ";
        }

        for(int j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i =5,k = 0;i>=1,k<3;i-=2,k++)
    {
        for(int l = 0;l<=k;l++)
        {
            cout<<" ";
        }
        
        for(int j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    f();
    system("pause");
}