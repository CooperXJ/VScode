#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int tan[10][11] = {0};
    tan[0][1] = 1;

    for(int i = 1;i<10;i++)
    {
        for(int j = 1;j<=i+1;j++)
        {
            tan[i][j] = tan[i-1][j]+tan[i-1][j-1];
        }
    }

    for(int i = 0;i<10;i++)
    {
        for(int j = 1;j<=i+1;j++)
        {
           cout<<tan[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
}