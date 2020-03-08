#include <iostream>
#include <math.h>
using namespace std;

void f(int val)
{
    char a[100];
    int i = 0;
    while(val!=0)
    {
        a[i++] = val%10+'0';//这里必须要注意+‘0’,否则会将数字n放入到a中，而数字n对应的字符串则不是字符串对应的‘n’
        val/=10;
    }

    for(int j = i-1;j>=0;j--)
    {
        cout<<a[j];
    }
    cout<<endl;
}

int main()
{
    f(123456789);
    system("pause");
}