#include <iostream>
#include <math.h>
using namespace std;

void Fun(char *s,char t)
{
    while(*s)
    {
        if(*s==t)
            *s=t-'a'+'A';
        s++;//遍历字符串
    }
}

int main()
{
    char str1[20] = "abcddfe",c='d';
    Fun(str1,c);
    printf("%s\n",str1); //abcDDfe

    char *s = str1;
    while(*(s)!='\0')
    {
        cout<<*(s);
        s++;
    }
    cout<<endl;
    system("pause");
}