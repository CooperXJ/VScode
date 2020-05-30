#include <iostream>
#include <math.h>
using namespace std;

void f(int *a)
{
    for(int i =0;i<7;i++)
    {
        int min = i;
        for(int j = i+1;j<7;j++)
        {
            if(a[min]>a[j])
                min = j;
        }

        int t = a[i];
        a[i] = a[min];
        a[min] = t; 
    }

    for(int i =0;i<7;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[] = {3,2,1,4,5,3,7};
    f(a);
    system("pause");
}