#include <iostream>
#include <math.h>
using namespace std;


void f(int n)
{
   int i;
   if((i=n/10)!=0)
   {
       f(i);
   }
    cout<<n%10<<endl;
}

int main()
{
    f(483);
    system("pause");
}