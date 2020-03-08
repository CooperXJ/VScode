#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <malloc.h>
using namespace std;

/*
    对二维字符串进行操作的时候，可以先将其首地址存入到指针数组当中，然后将指针数组传入函数，对其进行操作
*/
bool compare(string s1,string s2)
{
    if(s1>s2)
        return false;
    else
    {
        return true;
    }
    
}

void f(vector<string> v)
{
    sort(v.begin(),v.end(),compare);
    for(auto i : v)
        cout<<i<<endl;
}

void foo(char **s)
{
    for(int i =0;i<3;i++)
    {
        for(int j =i+1;j<3;j++)
        {
            //strcmp  注意一下  两字符串相同为0  前者比后者大为1  后者比前者大为-1
            if(strcmp(*(s+i),*(s+j))>0)
            {
                char *t = *(s+i);
                *(s+i) = *(s+j);
                *(s+j) = t;
            }
        }
    }

    for(int i =0;i<3;i++)
        cout<<*(s+i)<<endl;
}

int main()
{
    vector<string> v;
    v.push_back("China");
    v.push_back("Japan");
    v.push_back("Yemen");
    v.push_back("Pakistan");
    v.push_back("Mexico");
    v.push_back("Korea");
    v.push_back("Iceland");
    v.push_back("Canada");
    v.push_back("Mongolia");
    f(v);

    // char p[][20] = {"China","Japan","Canada"};
    // char *s[3];
    // for(int i =0;i<3;i++)
    //     s[i] = p[i];
    
    // foo(s);

    // cout<<strcmp("1","2")<<endl;
    // cout<<strcmp("3","2")<<endl;
    system("pause");
}