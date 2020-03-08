#include <iostream>
#include <math.h>
using namespace std;

int find_age(int n)
{
    if(n==1)
    {
        return 10;
    }
    else
    {
        return find_age(n-1)+2;
    }
    
}

int main()
{
    cout<<find_age(5)<<endl;
    system("pause");
}