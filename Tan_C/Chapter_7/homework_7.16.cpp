#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int f(char *ch)
{
    int res = 0;
    for(int i =0,j = strlen(ch)-1;ch[i]!='\0',j>=0;i++,j--)
    {
        if(ch[i]>='0'&&ch[i]<='9')
        {
            res+=pow(16,j)*(ch[i]-'0');
        }
        else if (ch[i]>='a'&&ch[i]<='z')
        {
            res+=pow(16,j)*(ch[i]-'a'+10);
        }
        else
        {
            res+=pow(16,j)*(ch[i]-'A'+10);
        } 
    }
    return res;
}

void binary_transrom(int val)
{
    int i = val,j = 0;
    int a[1000];
    while(i)
    {
        a[j] = i%2;
        i/=2;
        j++;
    }
    //原来得出的字符串是反的，所以需要转变输出一下
    for(int i = j-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    char a[] = "A10";
    cout<<f(a)<<endl;
    cout<<16*16*10+16<<endl;
    binary_transrom(3);
    system("pause");
}