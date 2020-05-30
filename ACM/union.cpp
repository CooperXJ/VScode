#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int pre[1010];

int unionsearch(int root)
{
    int son,tmp;
    son = root;
    while(root!=pre[root])
        root = pre[root];
    
    while(son!=root)
    {
        tmp = pre[son];
        pre[son] = root;
        son = tmp;
    }

    return root;
}

int main()
{
    int num,road,total,i,start,end,root1,root2;
    while(scanf("%d%d",&num,&road)&&num)
    {
        total = num - 1;
        for(i = 1;i<=num;++i)
            pre[i] = i;
        while(road--)
        {
            scanf("%d%d",&start,&end);
            root1 = unionsearch(start);
            root2 = unionsearch(end);
            if(root1!=root2)
            {
                pre[root1] = root2;
                total--;
            }
        }

        printf("%d\n",total);
    }

    system("pause");
}