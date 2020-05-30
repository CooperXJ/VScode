#include <iostream>
#include <math.h>
using namespace std;

int f()
{
    int peach_number = 1;
    //此处的n必须为9，因为第十天的已经计算出来了
    int n =9;

    while (n!=0)
    {
        n--;
        peach_number = (peach_number+1)*2; 
    }
    
    return peach_number;
}

int main()
{
    cout<<f()<<endl;
    system("pause");
}