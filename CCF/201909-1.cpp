#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;


    int **a = (int**)malloc(sizeof(int*)*m);
    for(int i =0;i<m;i++)
    {
        *(a+i) = (int*)malloc(sizeof(int)*(n+1));
    }

    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    int *tree = (int*)malloc(sizeof(int)*m);
    memset(tree,0,sizeof(int)*m);

    int sum = 0;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<=n;j++)
        {
            sum+=a[i][j];
        }
    }
    cout<<sum<<" ";

    for(int i = 0;i<m;i++)
    {
        for(int j =1;j<=n;j++)
        {
            tree[i]+= a[i][j];
        }
    }

    int min = tree[0];
    for(int i = 0;i<m;i++)
    {
        if(tree[i]<min)
            min = tree[i];
    }

    for(int i =0;i<m;i++)
    {
        if(tree[i]==min)
        {
            cout<<i+1<<" "<<-min;
            break;
        }
    }

    system("pause");
}