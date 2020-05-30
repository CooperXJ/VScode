#include <iostream>
#include <math.h>
using namespace std;

void move(char a,char b)
{
    cout<<a<<"->"<<b<<endl;
}

void hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        move(a,c);
    }
    else
    {
        hanoi(n-1,a,b,c);
        move(a,b);
        hanoi(n-1,b,a,c);
    }
    
}

int main()
{
    hanoi(3,'A','B','C');
    system("pause");
}