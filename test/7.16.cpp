#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int get_val(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return ch - 48;
    }

    else
    {
        return ch - 'A'+10;
    }
    
}
int transform(char* val)
{ 
    int res = 0;
    for(int i =strlen(val)-1,j = 0;i>=0;i--)
    {
        res+=pow(16,i)*get_val(val[j++]);
    }

    return res;
}

int htoi(char s[])
{
    int i ,n;
    n = 0;
    for(i = 0;s[i]!='\0';i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            n = n*16+s[i] - '0';
        }

        else if(s[i]>='a'&&s[i]<='f')
            n = n*16+s[i] - 'a'+10;
        else
        {
            n = n*16+s[i] - 'A'+10;
        }
        
    }

    return n;
}

int btoi(char s[])
{
    int i ,n;
    n = 0;
    for(i = 0;s[i]!='\0';i++)
    {
        n = n*2 +s[i] - '0';
    }

    return n;
}

void * binary_transform(int n)
{
    int i,j = 0;
    i = n;
    int a[1000];
    while(i)
    {
        a[j] = i%8;
        i/=8;
        j++;
    }

    for(int i = j-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    char val[] = "A11";
    char val1[] = "1111111";
    // cout<<strlen(val)<<endl;
    // cout<<transform(val)<<endl;
    // cout<<htoi(val)<<endl;
    // cout<<btoi(val1)<<endl;

    int a = 16;
    binary_transform(a);
    system("pause");
}