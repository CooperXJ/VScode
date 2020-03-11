#include <iostream>
#include <math.h>
using namespace std;

int Paration(int *arr,int low,int high)
{
    int a = arr[low];
    
    while (low<high)
    {
       while (low<high&&arr[high]>a)
       {
           high--;
       }

        arr[low] = arr[high];

        while (low<high&&arr[low]<a)
        {
            low++;
        }
        
        arr[high] = arr[low];
    }
    
    arr[low] = a;
    return low;
}

void Quick_Sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = Paration(arr,low,high);
        Quick_Sort(arr,low,mid-1);
        Quick_Sort(arr,mid+1,high);
    }
}

int main()
{
    int arr[] = {1,3,2,4,6,5};
    Quick_Sort(arr,0,5);
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
    
    system("pause");
}