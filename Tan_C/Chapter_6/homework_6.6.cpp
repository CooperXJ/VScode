#include <iostream>
#include <math.h>
using namespace std;

void show(int line_number)
{
    int arr[10][10] = {0};
    for(int i =0;i<10;i++)
    {
        arr[i][0] = 1;
    }

    for(int i =1;i<line_number;i++)
    {
        for(int j =1;j<=i;j++)
        {
            arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
        }
    }

    for(int i =0;i<10;i++)
    {
        for(int j =0;j<=i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    show(10);
    system("pause");
}