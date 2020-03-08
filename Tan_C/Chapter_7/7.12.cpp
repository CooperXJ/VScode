#include <iostream>
#include <math.h>
using namespace std;

void choose_sort(int *arr,int n)
{
    for(int i =0;i<n;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }

        //swap
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[] = {4,3,2,1,5};
    choose_sort(arr,5);
    system("pause");
}