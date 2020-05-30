#include <iostream>
#include <math.h>
using namespace std;

#define M(x,y)x*y
#define M(x,y) ((x)*(y))
int main()
{
    int a = 1,b = 2,c =3;
    printf("%d\n",M(a+b,b+c));//3 5
    system("pause");  //a+b*b+c  
}