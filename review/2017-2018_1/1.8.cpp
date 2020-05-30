#include <iostream>
#include <math.h>
using namespace std;

int Fun()
{
    int b = 0;
    static int c = 3;
    b++;
    c++;
    return (b+c);
}

int main()
{
    int i;
    for(int i =0;i<3;i++)
        printf("%3d",Fun());//1+4 1+5 1+6

    system("pause");
}