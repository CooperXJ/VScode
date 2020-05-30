#include <iostream>
#include <math.h>
using namespace std;

void Fun(int a[],int n)
{
    int i,j,m,temp;
    for(j=0;j<n-1;j++)
    {
        for(m = j,i=j+1;i<n;i++)
            if(a[i]>a[m])
                m = i;
        if(m!=j)
        {
            temp = a[m];
            a[m] = a[j];
            a[j] = temp;
        }
    }
}

int main()
{
    int i,a[5] = {1,5,4,3,7};
    Fun(a,5);
    for(i=0;i<5;i++)
        cout<<a[i];//7 5 4 3 1
    cout<<endl;

    system("pause");
}