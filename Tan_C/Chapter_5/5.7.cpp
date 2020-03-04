#include <iostream>
#include <math.h>
using namespace std;

float Calculate()
{
    float i = 1;
    float res = 0;
    int j = 1;
    int flag = 0;
    while((i/j)>=1e-6)
    {
        res+=pow(-1,flag)*i/j;
        j+=2;
        flag++;
    }

    return res;
}

int main()
{
    cout<<Calculate()*4<<endl;
    system("pause");
}