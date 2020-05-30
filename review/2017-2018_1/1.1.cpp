#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x = 75;
    printf("%d,%.2f,%.2f,%d\n",x/10,(float)x/10,(float)(x/10),-x%10);//7 7.50 7.00 -5
    system("pause");
}