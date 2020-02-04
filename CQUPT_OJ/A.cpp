#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char ** arr = (char**)malloc(sizeof(char *)*n);
    for(int i =0;i<n;i++)
    {
        arr[i] = (char*)malloc(sizeof(char*)*n);
    }

    for(int i =0;i<n;i++)
    {
        arr[0][i] = 'a'+i;
    }

    for(int i=1;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i+j==n-1)
            {
                arr[i][j] = arr[0][n-1];
            }
            else
            {
                arr[i][j] = 'a'+i+j;
            }
            
        }
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    system("pause");
}