#include <iostream>
#include <math.h>
using namespace std;

void f(int times)
{
    double sum_height = 100;
    double base_height = 100;

    for(int i =0;i<times;i++)
    {
        base_height/=2;
    }
    
    cout<<base_height<<endl;

    //只能加9次，因为第一次下降只有下降的100，没有反弹到和他原来的高度
    base_height = 100;
    for(int i =1;i<times;i++)
    {
        sum_height+=base_height;
        base_height/=2;
    }

    cout<<sum_height<<endl;
}

int main()
{
    f(10);
    system("pause");
}