#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string number;
    cin>>number;

    long long sum = 0;//注意最后的数字的结果数目位数
    for(int i = 0 ;i<number.length();i++)//刚刚开始的时候写反了
    {
        if(number[i]=='A')
        {
            sum+=pow(16,number.length()-i-1)*10;
        }
        else if(number[i]=='B')
        {
            sum+=pow(16,number.length()-i-1)*11;
        }
         else if(number[i]=='C')
        {
            sum+=pow(16,number.length()-i-1)*12;
        }
         else if(number[i]=='D')
        {
            sum+=pow(16,number.length()-i-1)*13;
        }
         else if(number[i]=='E')
        {
            sum+=pow(16,number.length()-i-1)*14;
        }
         else if(number[i]=='F')
        {
            sum+=pow(16,number.length()-i-1)*15;
        }
        else
        {
            sum+=pow(16,number.length()-i-1)*(number[i]-'0');
        }
        
        
    }

    cout<<sum<<endl;
    system("pause");

}