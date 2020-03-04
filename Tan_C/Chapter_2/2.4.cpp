#include <iostream>
#include <math.h>
using namespace std;

void sum()
{
    double res = 0;
    for(int i =1;i<101;i++)
    {
        if(i%2==0)
            res-=1.0/i;
        else
        {
            res+=1.0/i;
        }
        
        
    }

    cout<<res<<endl;
}

int main()
{
    sum();
    system("pause");
}