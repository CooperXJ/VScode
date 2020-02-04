#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
int main() {
    int n,m,count;
    scanf("%d%d",&n,&m);
    count=n*m;
    int **a = (int**)malloc(sizeof(int*)*m);
    int k;
    for(k =0;k<m;k++)
    {
        a[k] = (int*)malloc(sizeof(int)*n);
    }
    
    //int a[n][m],i,j;
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    //**********以上是数的输入**************
    int t=0;//t用于记录圈数
    i=0;//数的横坐标
    j=0;//数的纵坐标
    while(count) {
    //省略if(i==t&&j==t&&count)，判断坐标是否在左上角的节点，因为条件必然成立
        while(i<n-t&&count) {//从左上角向下走
            if(i==0&&j==0) {//第一个数的输出格式
                printf("%d",a[0][0]);
                i++;
            } else
                printf(" %d",a[i++][j]);
            count--;
        }
        i--;//这个时候i已经多加了1
        j++;
        //省略if(i==n-1-t&&j==t)，左下角的节点的判断
        while(j<m-t&&count) {//向右走
            printf(" %d",a[i][j++]);
            count--;
        }
        j--;
        i--;
        //省略if(i==n-1-t&&j==m-1-t&&count)，右下角节点的判断
        while(i>=t&&count) {//向上走
            printf(" %d",a[i--][j]);
            count--;
        }
        i++;
        j--;
        //省略if(i==t&&j==m-1-t)，右上角节点的判断
        while(j>t&&count) {//向左走
            printf(" %d",a[i][j--]);
            count--;
        }
        j++;
        i++;
        t++;//圈数加一
    }
    system("pause");
    return 0;
}
