#include <iostream>
#include <math.h>
using namespace std;

void move(char A,char B)
{
    printf("%c->%c\n",A,B);
}

void f(int i,char A,char B,char C)
{
    if(i==1)
    {
        move(A,C);
    }
    else
    {
        //A通过C盘将n-1个盘子移动到B盘上，这样剩下的一个盘可以直接移动到C盘上
        f(i-1,A,C,B);
        //A直接移动到C盘上
        move(A,C);
        //B盘剩下的通过A盘移动到C盘上
        f(i-1,B,A,C);
    } 
}

int main()
{
    f(100,'A','B','C');
    system("pause");
}