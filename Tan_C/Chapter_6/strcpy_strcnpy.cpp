#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

/*
    1.strncpy与strcpy的区别在于前者是可以选择字符串的n位，strcpy只能整个字符串的复制
*/
int main()
{
    char a[] = "123";
    char b[] = "234";
    char c[10];
    //strcpy(b,a);
    //strncpy(b,a,1);
    strncpy(c,a,1);
    //cout<<b<<endl;
    cout<<c<<endl;
    system("pause");
}