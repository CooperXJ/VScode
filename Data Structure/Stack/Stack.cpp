#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(11);
    s.push(12);
    for(int i =0;i<s.length();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
