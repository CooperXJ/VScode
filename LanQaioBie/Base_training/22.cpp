#include <iostream>
using namespace std;

string res(int n)
{
    if(n==1)
    {
        string str = "A";
        return str;
    }

    else
    {
        string t = "A";
        t[0] += (n-1);
        return res(n-1)+t+res(n-1);
    }
    
}

int main()
{
    int N;
    cin>>N;

    cout<<res(N)<<endl;
    system("pause");
    
}