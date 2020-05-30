#include <stdio.h>

int main()
{
    int x = 10,y = 20,t = 0;
    if(x==y)
        t = x;
    x = y;
    y = t;
    printf("%d,%d\n",x,y);//20 0
    getchar();
}