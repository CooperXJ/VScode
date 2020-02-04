#include <iostream>
using namespace std;

double f(double i)
{
    if(i==1)
    {
        return 1;
    }
    else
        return 1.0/(1+f(i-1));
}
int main()
{
    cout.precision(3);
    cout<<fixed<<f(100)<<endl;
    system("pause");
}