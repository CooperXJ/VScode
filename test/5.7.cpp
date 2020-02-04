#include <iostream>
#include <math.h>
using namespace std;

void judge(int val)
{
    int bai = val/100;
    int shi = (val/10)%10;
    int ge = val - bai*100-10*shi;

    if(pow(bai,3)+pow(shi,3)+pow(ge,3)==val)
    {
        cout<<val<<endl;
    }
}
int main()
{
    for(int i =100;i<1000;i++)
    {
        judge(i);
    }
    system("pause");
}