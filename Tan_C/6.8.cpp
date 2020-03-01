#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int **arr = (int**)malloc(sizeof(int*)*n);

    for(int i =0;i<n;i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*m);
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    int an_point = arr[0][0];
    int flag = 1;
    int flag_sum = 0;

    int col;
    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(an_point<arr[i][j])
            {
                an_point = arr[i][j];
                col = j;
            }
        }

        for(int k = 0;k<n;k++)
        {
            if(an_point>=arr[k][col]&&k!=i)
            {
                flag = 0;
            }
        }

        if(flag==1)
        {
            flag_sum++;
            printf("a[%d][%d] = %d\n",i,col,arr[i][col]);
        }
    }

    if(flag_sum<1)
    {
        cout<<"It is not exist"<<endl;
    }

    system("pause");
}