#include <iostream>
#include <math.h>
using namespace std;

void sort(int **p)
{
    for(int i=0;i<7;i++)
    {
        for(int j =i+1;j<7;j++)
        {
            if(**(p+i)>**(p+j))
            {
                int *t = *(p+j);
                *(p+j) = *(p+i);
                *(p+i) = t;
            }
        }
    }
}

int main()
{
    int a[7] = {1,12,22,34,56,65,98};
    int *p[7];
    for(int i =0;i<7;i++)
    {
        p[i] = &a[i];
    }

    sort(p);
    for(auto i : a)
        cout<<i<<" ";
    cout<<endl;
    system("pause");
}