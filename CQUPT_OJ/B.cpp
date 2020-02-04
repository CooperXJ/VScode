#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;


int main()
{
    long long int n;
    cin>>n;
    bitset<32> t(n);
   cout<<pow(2,32)<<endl;

    long long int sum = 0;
    for(int i =0;i<t.size();i++)
    {
        if(t[i]!=0)
        {
            sum+=pow(2,t.size()-i-1);
        }
            
    }
    cout<<sum<<endl;
        
    //cout<<pow(2,31)<<endl;
    system("pause");
}