#include <iostream>
#include <vector>
using namespace  std;

int main()
{
    vector<string> str;
    for(int i =0;i<2;i++)
    {
        string s;
        cin>>s;
        str.push_back(s);
    }
    
    for(int i =0;i<2;i++)
    {
        int j;
       for(j =1;j<str[i].length();j++)
       {
           if(j%8==0)
           {
               for(int k=j-7;k<=j;k++)
               {
                   cout<<str[i][j];
               }
               cout<<endl;
           }
          
               
       }

               for(int k = j-8*(j/8);k<str[i].length();k++)
               {
                   cout<<str[i][k];
               }
               for(int k =0;k<8*((j/8)+1)-str[i].length();k++)
               {
                   cout<<0;
               }
               cout<<endl;
       
    }
    system("pause");
}
