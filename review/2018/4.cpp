#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int corner = n-1;
    int count = 1;
    int arr[n][n];

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }

    int left = 0,right = n-1,top = 0,bottom = n-1;
    int circle = 0;

    while(count!=(n*n+1))
    {
        if(right>=0)
        {
            for(int i =0;i<corner;i++)
            {
                arr[top][i+circle] = count++;
            }

            for(int i =0;i<corner;i++)
            {
                arr[i+circle][right] = count++;
            }

            
            for(int i =corner;i>=1;i--)
            {
                arr[bottom][i+circle] = count++;
            }

            for(int i =corner;i>=1;i--)
            {
                arr[i+circle][left] = count++;
            }
        }

        left++;
        right--;
        top++;
        bottom--;
        corner-=2;
        circle++;
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    system("pause");
}