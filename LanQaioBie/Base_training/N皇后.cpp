#include <iostream>
#include <malloc.h>
#include <math.h>
using namespace std;

int count = 0;

int check(int row,int col,int *arr)
{
    for(int i =0;i<row;i++)
    {
        if(col == arr[i]||abs(col-arr[i])==abs(row-i))
            return 0;
    }

    return 1;
        
}

void findQueen(int k,int N,int *arr)
{
    if(k==N)
    {
        count++;
        return;
    }

    for(int i =0;i<N;i++)
    {
        if(check(k,i,arr))
        {
             cout<<k<<"   "<<i<<"    "<<i<<endl;
            arr[k] = i;
            findQueen(k+1,N,arr);
        }
    }
}

int main()
{
    int N;
    cin>>N;

    int *arr = (int*)malloc(sizeof(int)*N);
    for(int i = 0;i<N;i++)
    {
        arr[i] = 6;
    }
    
    findQueen(0,N,arr);
    cout<<count<<endl;

    system("pause");
}
    

