#include <iostream>
using namespace std;

int main()
{
    int target;
    cin>>target;

    int sum = 0;
   for(int i =1;i<10;i++)//1的话 不需要再次输出了
   {
       for(int j =0;j<10;j++)
       {
           for(int k = 0;k<10;k++)
           {
               for(int l=0;l<10;l++)
               {
                   for(int m = 1;m<10;m++)
                   {
                       sum = i+j+k+l+m;
                       if(i==m&&j==l&&sum==target)
                       {
                              cout<<i<<j<<k<<l<<m<<endl;
                       }
                    
                   }
               }
           }
       }
   }

    sum = 0;
   for(int i =1;i<10;i++)
   {
       sum+=i;
       for(int j =0;j<10;j++)
       {
           for(int k = 0;k<10;k++)
           {
               for(int l=0;l<10;l++)
               {
                   for(int m = 0;m<10;m++)
                   {
                       for(int n =1;n<10;n++)
                       {
                           sum = i+j+k+l+m+n;
                           if(i==n&&j==m&&sum==target&&k==l)
                            {
                                cout<<i<<j<<k<<l<<m<<n<<endl;
                            }
                       }
                    
                   }
               }
           }
       }
   }

   system("pause");
}