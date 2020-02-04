#include <iostream>
#include <malloc.h>
using namespace std;

int **multiply(int **arr, int n, int N)
{
    if(n==0)//矩阵的0次方为单位阵
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(i!=j)
                    arr[i][j] = 0;
                else
                {
                    arr[i][j] = 1;
                }
                
            }
        }
        return arr;
    }

    else if (n == 1)
    {
        return arr;
    }
    else
    {
        int **arr1 = multiply(arr, n - 1, N);
        int **arr2 = (int **)malloc(sizeof(int *) * N);
        for (int i = 0; i < N; i++)
        {
            arr2[i] = (int *)malloc(sizeof(int) * N);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr2[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    arr2[i][j] += arr[i][k] * arr1[k][j];
                }
            }
        }

        return arr2;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int **arr = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * N);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **res = multiply(arr, M, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}