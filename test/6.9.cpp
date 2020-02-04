#include <iostream>
#include <math.h>
using namespace std;

int mid_find(int low,int high,int *arr,int val)
{
    int mid = (low+high)/2;

    if(arr[mid]==val)
    {
        return mid+1;
    }

    else if(low<high)
    {
        if(val<arr[mid])
        {
            mid_find(low,mid-1,arr,val);
        }

        else if(val>arr[mid])
        {
            mid_find(mid+1,high,arr,val);
        }
        
    } 
    
    else
    {
        return -1;
    }
       

}
int main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int val = 10;
    cout<<mid_find(0,8,arr,val)<<endl;

    system("pause");
}