#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string s[7] = {"I","AM","A","OK","BOY","VERY","OK"};

    int i,j = 6;
    for(int i =0;i<j;i++)
    {
        if(s[i][0]=='A')
        {
            for(;j>i;j--)
            {
                if(s[j][(s[j]).length()-1]=='K')
                {
                    string t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                    break;
                }
            }
        }   
    }

    for(int i =0;i<7;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    system("pause");
}