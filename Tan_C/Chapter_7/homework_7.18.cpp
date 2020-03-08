#include <iostream>
#include <math.h>
using namespace std;

int leap_year(int year)
{
    if(year%4==0)
    {
        if(year%100!=0||year%400)
            return 1;
        else
        {
            return 0;
        }
        
    }
    else
    {
        return 0;
    }   
}

int sum_day(int year,int month,int day)
{
    int month_arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int res = 0;
    
    for(int j = 0;j<=month-1;j++)
    {
        for(int i = 0;i<13;i++)
        {
           if(j==i&&j==2&&leap_year(year))
           {
              res+=(month_arr[i]+1);
           }
           else if(j==i)
           {
               res+=month_arr[i];
           }
        }
    }

    return res+day;
}

int main()
{
    cout<<sum_day(2008,8,8)<<endl;
    system("pause");
}