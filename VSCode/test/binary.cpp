#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;


    int j = 0;

    int a[1000];

    while(n)
    {
        a[j] = n%2;
        n/=2;
        j++;
    }

    for(int i = j-1;i>=0;i--)
        cout<<a[i];
        cout<<endl;
        system("pause");
}