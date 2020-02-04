#include <iostream>
using namespace std;

int main()
{
    string num1;
    string num2;
    cin>>num1>>num2;

    int a[101] = {0};
    int k = 100;


    int c = 0;
    int length = num1.length()>num2.length()?num1.length()-num2.length():num2.length()-num1.length();

    if(num1.length()>num2.length())
    {
   for(int i = num2.length()-1;i>=0;i--)
   {
       int res = num1[i+length]-'0'+num2[i]-'0'+c;
       if(res<10)
       {
         a[k] = res;
         k--;
       }
      
      else
      {
          c = res-10;
          a[k-1] +=1;
          a[k] += c;
          k--;
      }
      
   }                   


    cout<<"K   "<<k<<endl;

    }

    
    else if(num1.length()<=num2.length())
    {
        for(int i = num1.length()-1;i>=0;i--)
   {
       int res = num1[i]-'0'+num2[i+length]-'0';
       if(res<10)
       {
         a[k] = res;
         k--;
       }
      
      else
      {
          res-=10;
          a[k-1] +=1;
          a[k] += res;
          k--;
      }
      
   }

    }


     for(int i =0;i<101;i++)
       {
           cout<<a[i];
       }
       cout<<endl;


   if(num1.length()>num2.length())
   {
       for(int i =num1.length()-(100-k)-1;i>=0;i--)
       {
          if( (a[k] += num1[i]-'0')<10)
           {
                a[k] += num2[i]-'0';
           }

           else
           {
                 a[k-1]+=1;
                 a[k]-=10;
           }
           k--;
       }

       

       for(int i =k;i<101;i++)
       {
           cout<<a[i];
       }
       cout<<endl;
       system("pause");
   }

   else
   {
       for(int i =num2.length()-(100-k)-1;i>=0;i--)
       {
           if( (a[k] += num2[i]-'0')<10)
           {
                a[k] += num2[i]-'0';
           }

           else
           {
                 a[k-1]+=1;
                 a[k]-=10;
           }
           k--;
       }



       for(int i =k;i<101;i++)
       {
           cout<<a[i];
       }
       cout<<endl;
        system("pause");
   }

    
}
