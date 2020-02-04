#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int m;
    cin>>m;//apple tree 的棵树

    int **a = (int**)malloc(sizeof(int*));
    int *len = (int*)malloc(sizeof(int)*m);
    for(int i = 0;i<m;i++)
    {
        int n;
        cin>>n;
        len[i] = n;
        for(int j = 0;j<n;j++)
        {
            *(a+i) = (int*)malloc(sizeof(int));
        }

        for(int j =0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int *tree_flag = (int*)malloc(sizeof(int)*m);//标记是否落了苹果
    int *tree_count = (int*)malloc(sizeof(int)*m);//统计每个棵苹果树的apple
    memset(tree_flag,0,sizeof(int)*m);
    memset(tree_count,0,sizeof(int)*m);

    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<len[i];j++)
        {
            tree_count[i]+=a[i][j];
            if(a[i][j+1]>0&&j!=0&&(j+1)<len[i])
            {
                if(a[i][j+1]!=tree_count[i])
                {
                    tree_count[i] = a[i][j];
                    tree_flag[i] = 1;
                }
            }
        }
    }

    memset(tree_count,0,sizeof(int)*m);
    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<len[i];j++)
        {
            tree_count[i]+=a[i][j];
            if(a[i][j]>0&&j!=0)
            {
                if(a[i][j]!=tree_count[i])
                {
                    tree_count[i] = a[i][j];
                }
            }
        }
    }

    int t = 0,d = 0,e = 0;
    for(int i =0;i<m;i++){

        t+=tree_count[i];
        if(tree_flag[i]==1)
        {
            d++;
        }
        if(tree_flag[i]==1&&tree_flag[(i+1)%m]==1&&tree_flag[(i+2)%m]==1)
        {
            e++;
        }
    }
        cout<<t<<" "<<d<<" "<<e<<endl;
        system("pause");
}
    
