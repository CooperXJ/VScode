#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a  =2;

    int sum = 0;
    int add;
    for(int i =0;i<n;i++)
    {
        add = 0;
        for(int j =0;j<=i;j++)
        {
            add+=pow(10,j)*a;
        }
        sum+=add;
    }

    cout<<sum<<endl;
    system("pause");
}