#include <iostream>
#include <math.h>
using namespace std;

int max_gongyue(int m,int n)
{
    int r = m;
    while(r!=0)
    {
        r = m%n;
        m = n;
        n = r;
    }

    return m;

}

int gcd(int m,int n)
{
    return m*n/max_gongyue(m,n);
}
int main()
{
    cout<<gcd(54,27)<<endl;
    system("pause");
}