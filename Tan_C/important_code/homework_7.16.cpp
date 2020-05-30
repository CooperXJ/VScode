#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int f(char *str)
{
    int res = 0;
    for(int i =0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            res =16*res+(str[i]-'A'+10);
        }
        else if(str[i]>='a'&&str[i]<='z')
        {
            res =16*res+(str[i]-'a'+10);
        }
        else
        {
            res =16*res+(str[i]-'0');
        }
        
    }
    return res;
}

int f1(char *str)
{
    int res = 0;
    for(int i =0;str[i]!='\0';i++)
    {
        res = res*2+str[i]-'0';
    }
    return res;
}

void f2(int n)
{
    char str[100];
    int k = 0;

    while(n!=0)
    {
        str[k++] = n%2+'0';
        n = n/2;
    }

    for(int i =k-1;i>=0;i--)
    {
        cout<<str[i];
    }
    cout<<endl;
}

void f3(int n)
{
    char str[100];
    int k = 0;

    while(n!=0)
    {
        if(n%16>9)
        {
            str[k++] = n%16+'A'-10;
        }
        else
        {
            str[k++] = n%16+'0';
        }
        
        n = n/16;
    }

    for(int i =k-1;i>=0;i--)
    {
        cout<<str[i];
    }
    cout<<endl;
}

int main()
{
    char str[] = "11";
    // cout<<f(str)<<endl;
    // cout<<f1(str)<<endl;
    f2(8);
    f3(2577);
    system("pause");
}