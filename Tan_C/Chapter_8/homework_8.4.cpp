#include <iostream>
#include <math.h>
#include <string.h>
#include <malloc.h>
using namespace std;

void f(char *str,int m)
{
    char *s = (char*)malloc(sizeof(char)*(strlen(str)+1));//这里不能忘记最后的‘\0’漏掉，否则会出现问题

    for(int i= 0;i<strlen(str);i++)
    {
        s[(i+m)%strlen(str)] = str[i];
    }

    s[strlen(str)] = '\0';

    cout<<s<<endl;  
}

void f1(int *a,int m)
{
    int len = 8;
    int *arr = (int*)malloc(sizeof(int)*len);

    for(int i =0;i<len;i++)
    {
        arr[(i+m)%len] = a[i];
    }

    for(int i =0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test()
{
    static int a = 1;
}

int main()
{
    // char str[] = "";
    // f(str,2);

    // int a[] = {12,43,65,67,8,2,7,11};
    // f1(a,4);

    test();
    cout<<"1"<<endl;
    system("pause");
}