#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num[23];

bool cmp(const string &a,const string &b)
{
    return a+b>b+a;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    sort(num,num+n,cmp);

    for(int i =0;i<n;i++)
    {
        cout<<num[i];
    }
    cout<<endl;
    system("pause");
}