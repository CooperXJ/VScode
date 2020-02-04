#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int res[100] = {0};
    string num1;
    string num2;
    cin>>num1>>num2;

    vector<int> vec1;
    vector<int> vec2;

    int lengthmax = num1.length()>num2.length()?num1.length():num2.length();
    int lengthmin = num1.length()<num2.length()?num1.length():num2.length();

    //vector<int> vec;
    int a[100] = {0};

    for(int i =0;i<num1.length();i++)
    {
        vec1.push_back(num1[i]-'0');
    }

    for(int i =0;i<num2.length();i++)
    {
        vec2.push_back(num2[i]-'0');
    }

    //补零
    if(num1.length()>num2.length())
    {
        for(int i =0;i<lengthmax-lengthmin;i++)
        vec2.insert(vec2.begin(),0);
    }
    else
    {
        for(int i =0;i<lengthmax-lengthmin;i++)
        vec1.insert(vec1.begin(),0);
    }
    
     vec1.insert(vec1.begin(),0);
     vec2.insert(vec2.begin(),0);

    int k =0;
    int c =0;
    for(int i =lengthmax;i>=0;i--)
    {
        int res = vec1[i]+vec2[i]+c;
        if(res<10)
        {
            c= 0;
            a[k] += res;
            k++;
        }
        else 
        {
           c = 1;
           a[k]+=(res-10);
           k++;
        }
           
    }

    int flag = 0;
    for(flag =99;flag>=0;flag--)
    {
       if(a[flag]!=0)
       {
        break;
       }
    }

    for(int i = flag;i>=0;i--)
    {
        cout<<a[i];
    }
     cout<<endl;
    system("pause");
    
}