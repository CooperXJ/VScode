#include <iostream>
#include <math.h>
using namespace std;

int word_count(char *str)
{
    int i =0,count = 1;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    char str[] = "I am a Chinese boy";
    cout<<word_count(str)<<endl;
    system("pause");
}