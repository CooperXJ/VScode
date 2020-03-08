#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void word_count(char *str)
{
    int da = 0;
    int xiao = 0;
    int space = 0;
    int number = 0;
    int other = 0;
    for(int i = 0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            da++;
        else if(str[i]>='a'&&str[i]<='z')
            xiao++;
        else if(str[i]==' ')
            space++;
        else if(str[i]>='0'&&str[i]<='9')
            number++;
        else
        {
            other++;
        }    
    }

    cout<<da<<" "<<xiao<<" "<<space<<" "<<number<<" "<<other<<endl;
}

int main()
{
    char str[] = "Today is 2008/8/8";
    word_count(str);
    system("pause");
}