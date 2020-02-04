#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int **arr = (int**)malloc(sizeof(int*)*n);
    for(int i =0;i<n;i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    int *arr1 = (int*)malloc(sizeof(int)*n);
    for(int i =0;i<n;i++)
    {
        arr1[i] = 0;
    }

    int k =0;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i==j)
                continue;

            if(arr[j][i]==1)
            {
                arr1[k]++;
            }
        }
        k++;
    }

    for(int i =0;i<n;i++)
    {
        if(arr1[i]>=(n/2))
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}