#include <iostream>
#include <math.h>
using namespace std;

void Fun(char a[])
{
    int j = 0,i;
    for(i = 0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            a[j++] = a[i];
        a[j] = '\0';
    }
}

int main()
{
    char s[20] = "sd83JKe3iE"; //833
    Fun(s);
    cout<<s<<endl;

    char ss[3] = {'1','\0','2'};
    cout<<ss<<endl;
    system("pause");
}