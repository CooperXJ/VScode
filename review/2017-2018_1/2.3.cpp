#include <iostream>
#include <math.h>
using namespace std;

bool is_huiwen(string s)
{
    for(int i =0,j=s.length()-1;s[i]!='\0',j>=0;i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }

    return true;
}

bool is_success(string s)
{
    int begin = 0;
    int end = s.length()-1;

    while(begin<=end)
    {
        if(s[begin]!=s[end])
        {
            return false;
        }

        begin++;
        end--;
    }

    return true;
} 

int main()
{
    string s = "abefeb";
    if(is_huiwen(s))
        cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }

    if(is_success(s))
        cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    system("pause");
}