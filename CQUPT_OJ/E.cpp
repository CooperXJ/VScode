#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int check(long long int a,long long int b,long long int x,long long int y)
{
   
   if(a>b)
   {
        if(x*x*b*b+y*y*a*a<=a*a*b*b)
        {
            return 1;
        }
   }
    else
    {
        if(x*x*a*a+y*y*b*b<=a*a*b*b)
        {
            return 1;
        }
    }
       


    return 0;  
}

int f2(long long int a,long long int b)

{

	while (b)

	{

	  int t=a%b;

	  a=b;

	  b=t; 	

	}

   return a;

}

int main()
{
    long long int a,b,n;
    cin>>a>>b>>n;

    int sum_1 = 0;

    long long int S_tri = 4*a*b;

    vector<int> vec;

    for(int i=0;i<n;i++)
    {
        int p1,p2;
        cin>>p1>>p2;
        vec.push_back(p1);
        vec.push_back(p2);
    }

    for(int i =0;i<n*2;i+=2)
    {
        if(a>b)
        {
             if(check(a,b,vec[i],vec[i+1]))
            {
                sum_1++;
            }
        }
        else
        {
             if(check(a,b,vec[i+1],vec[i]))
            {
                sum_1++;
            }
        }
       
    }
    
    
    long long int x = f2(sum_1*S_tri,n);
    if(sum_1*S_tri%n==0)
        cout<<sum_1*S_tri/n<<endl;
    else
    {
        cout<<sum_1*S_tri/x<<"/"<<n/x<<endl;
    }

    system("pause");
    
}