#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

/*两次n皇后即可*/
int count = 0;
int check(int row,int col,int **arr,int N)
{
    if(arr[row][col]==0)
        return 0;

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<N;j++)
        {
            if(arr[i][col]==2||(arr[i][j]==2&&abs(i-row)==abs(j-col)))
            return 0;
        }
    }

    return 1;
}

int check1(int row,int col,int **arr,int N)
{
    if(arr[row][col]==0||arr[row][col]==2)
        return 0;

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<N;j++)
        {
            if(arr[i][col]==3||(arr[i][j]==3&&abs(i-row)==abs(j-col)))
            return 0;
        }
    }

    return 1;
}

void findQueen_1(int row,int N,int **arr)
{
    if(row==N)
    {
        count++;
        return;
    }

    for(int i =0;i<N;i++)
    {
        if(check1(row,i,arr,N))
        {
            //cout<<row<<"   "<<i<<"    "<<row<<endl;
            arr[row][i] = 3;
            findQueen_1(row+1,N,arr);
            arr[row][i] = 1;//复原
        }
    }
}

void findQueen(int row,int N,int **arr)
{
    if(row==N)
    {
        findQueen_1(0,N,arr);
        return;
    }

    for(int i =0;i<N;i++)
    {
        if(check(row,i,arr,N))
        {
            //cout<<row<<"   "<<i<<"    "<<row<<endl;
            arr[row][i] = 2;
            findQueen(row+1,N,arr);
            arr[row][i] = 1;//复原
        }
    }
}
int main()
{
    int N;
    cin>>N;

    int **arr = (int**)malloc(sizeof(int*)*N);
    for(int i =0;i<N;i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*N);
    }

    for(int i =0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
/*
     for(int i =0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    findQueen(0,N,arr);
    cout<<count<<endl;

    system("pause");
}