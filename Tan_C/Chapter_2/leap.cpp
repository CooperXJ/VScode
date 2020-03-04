#include <iostream>
#include <math.h>
using namespace std;

//可以被4整除但是不能被100整除
//可以被400整除
void Judge_leap_year(int year)
{
    if(year%4==0)
    {
        if (year%100==0)
        {
            cout<<"not leap year"<<endl;
        }        
        else
        {
            cout<<"leap year"<<endl;
        }      
    }
    else
    {
        cout<<"not leap year"<<endl;
    }
    
}

int main()
{
    Judge_leap_year(2100);
    system("pause");
}