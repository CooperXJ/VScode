#include <iostream>
#include <math.h>
using namespace std;

/*
    最重要的一点就是这个l<h，因为mid是一直+1和-1的，所以一旦h=l的时候就会跳出循环
*/
int find_pos(int *a,int l,int h,int val)
{
    int mid = (l+h)/2;
    if(a[mid]==val)
    {
        return mid;
    }

    if(l<h)
    {
        if(val<a[mid])
        {
            find_pos(a,l,mid-1,val);
        }
        else
        {
            find_pos(a,mid+1,h,val);
        }
        
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a[] = {8,7,6,5,4,3,2,1};
    cout<<find_pos(a,0,7,10)<<endl;
    system("pause");
}