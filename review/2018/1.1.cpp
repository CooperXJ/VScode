#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    for(int i =0;i<=20;i++)
    {
        for(int j = 0;j<34;j++)
        {
            for(int k = 0;k<=300;k++)
            {
                if(i+j+k==100&&(k%3==0)&&i*5+j*3+(k/3)==100)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    system("pause");
}