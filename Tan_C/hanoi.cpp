#include <iostream>
#include <math.h>
using namespace std;

void move(char A,char B)
{
    printf("%c->%c\n",A,B);
}

void hanoi(int i,char A,char B,char C)
{
    if(i==1)
    {
        move(A,C);
    }
    else
    {
        hanoi(i-1,A,C,B);
        move(A,C);
        hanoi(i-1,B,A,C);
    }
    
}

int main()
{
    hanoi(64,'A','B','C');
    system("pause");
}