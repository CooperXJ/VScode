#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s = "abc/456abc";
    char res[100];
    strcpy(res,s.c_str());
    cout<<res<<endl;
    char str1[100],str2[100],str3[100];
    sscanf(res,"%[a-z]",str1);
    cout<<str1<<endl;
    system("pause");
}