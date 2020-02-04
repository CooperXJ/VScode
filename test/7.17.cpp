#include <iostream>
#include <math.h>
using namespace std;

void convert(int n)
{
    int i ;
    if((i = n/10)!=0)
        convert(i);
    putchar(n%10+'0');//此处需要%的原因在于当返回上一层的时候n = 45而不是4 并且最前面的一层为n = 345
    putchar(32);
}

int main()
{
    convert(345);
    system("pause");
}