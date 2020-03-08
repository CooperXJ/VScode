#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

int** transform_test(int (*arr)[3])
{
    int **p = (int**)malloc(sizeof(int*)*3);
    for(int i =0;i<3;i++)
    {
        p[i] = (int*)malloc(sizeof(int)*3);
    }

    for(int i =0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            p[j][i] = arr[i][j];
        }
    }

    return p;
}

int main()
{
    int a[][3] = {1,2,3,4,5,6,7,8,9};
    int **p = transform_test(a);

    for(int i =0;i<3;i++)
    {
        for(int j =0;j<3;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }

    system("pause");
}