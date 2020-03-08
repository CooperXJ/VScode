#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

void number_count(char *str)
{
    vector<string> v;
    string s;
    for(int i = 0;i<=strlen(str);i++)//这里需要=strlen()  因为最后一个无法去得到的话会出现最后一个数字无法识别的问题
    {
        if(isdigit(str[i]))
        {
            s.push_back(str[i]);
        }    
        else if(str[i]==' '||str[i]=='\0')
        {
            v.push_back(s);
            s.clear();
        }
    }

   for(auto i :v)
    cout<<i<<endl;
}

int main()
{
    char str[] = "123 4 qq";
    number_count(str);
    // char s[] = "123";
    // string str;
    // str.push_back('1');
    // cout<<str<<endl;

    system("pause");
}