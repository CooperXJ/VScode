#include <iostream>
#include <math.h>
#include <string.h>
#include <malloc.h>
using namespace std;

char *copy(char *str)
{
    char *res = (char *)malloc(sizeof(char)*strlen(str));
    for(int i=0;i<strlen(str);i++)
    {
        res[i] = str[i];
    }
    return res;
}

int main()
{
    // char str[] = "123";
    // cout<<copy(str)<<endl;
    char str[14];
    scanf("%s",str);
    cout<<str<<endl;
    system("pause");
}