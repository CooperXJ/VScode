#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 0,s= 0 ;
    do{
        if(i%2)
        {
            i++;//2  4  6
            continue;
        }
        i++;//1  3  5  7
        s+=i;//1  4  9 16
    }while(i<7);
    cout<<s<<endl; 

    system("pause");
}