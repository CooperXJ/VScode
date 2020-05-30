#include <iostream>
#include <math.h>
using namespace std;

int Fun(int n)//1 F(2) = F(1)+2 = 3 F(3) = F(2)+2 = F(1)+2+2 = 5
{
    if(n==1)
        return 1;
    else
    {
        return Fun(n-1)+2;
    }
}

int main()
{
    int i,re = 0;
    for(i=1;i<=3;i++)
        re+=Fun(i);
    printf("%d\n",re);//9

    system("pause");
}