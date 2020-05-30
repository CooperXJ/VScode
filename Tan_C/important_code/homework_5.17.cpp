#include <iostream>
#include <math.h>
using namespace std;

void f()
{
    for(char a = 'X';a<='Z';a++)
    {
        for(char b = 'X';b<='Z';b++)
        {
            for(char c = 'X';c<='Z';c++)
            {
                if(a!='X'&&c!='X'&&c!='Z'&&a!=b&&a!=c&&c!=b)//要注意这里a，b，c的对手也不能相同
                {
                    cout<<"A - "<<a<<endl;
                    cout<<"B - "<<b<<endl;
                    cout<<"C - "<<c<<endl;
                }
            }
        }
    }
}

int main()
{
    f();
    system("pause");
}