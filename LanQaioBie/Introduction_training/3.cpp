#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long res = n*(n+1)/2;
    printf("%lld\n",res);
    system("pause");
    return 0;
}