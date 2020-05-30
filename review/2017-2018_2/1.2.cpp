#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i,n = 0;
    for(i=2;i<5;i++)
    {
        do{
            if(i%3)
                continue;
            n++;
        }while(!i);
        n++;//1 3 4 
    }
    cout<<n<<endl;
    system("pause");
}