#include <iostream>
#include <math.h>
using namespace std;

int jiechen(int n)
{
    int result = 1;
    for(int i = 1;i<=n;i++)
    {
        result*=i;
    }

    return result;
}

int main()
{
    int result = 0;
    int n;
    cin>>n;

    for(int i =1;i<=n;i++)
    {
        result+=jiechen(i);
    }
    cout<<result<<endl;
    system("pause");
}