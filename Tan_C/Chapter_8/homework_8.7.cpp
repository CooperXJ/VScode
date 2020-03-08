#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void copy_n(char *target,char *source,int pos)
{
    int k = 0;
    for(int i = 0;i<strlen(source);i++)
    {
        if(i>=pos)
            target[k++] = source[i];
    }
}

int main()
{
    char s1[] = "1234";
    char s2[10] = "";
    copy_n(s2,s1,2);
    cout<<s2<<endl;
    system("pause");
}