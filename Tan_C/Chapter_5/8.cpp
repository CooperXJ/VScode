#include <iostream>
#include <math.h>
using namespace std;

void narcissistic_number(int range)
{
    for(int i =100;i<range;i++)
    {
        int ge = i%10;
        int shi = ((i-ge)/10)%10;
        int bai = i/100;

        double compare = pow(ge,3)+pow(shi,3)+pow(bai,3);
        if(compare==i)
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    narcissistic_number(1000);
    system("pause");
}