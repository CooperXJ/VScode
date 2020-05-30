#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[100] = {0};
    int k =0;
    while(n)
    {   
        a[k] = n%2;
        n/=2;
        k++;
    }

    for(int i =k-1;i>=0;i--)
        cout<<a[i];

    cout<<endl;
    system("pause");
}