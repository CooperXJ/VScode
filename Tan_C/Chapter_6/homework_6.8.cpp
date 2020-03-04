#include <iostream>
#include <math.h>
using namespace std;

void find_point(int (*p)[4])
{
    int i,j,k;
    int flag_sum = 0;

    for(i = 0;i<4;i++)
    {
        int max = p[i][0];
        int flag = 1;
        
        int max_j = 0;//这里必须有一个用来记录j的变量 因为直接使用j的话会出现问题，因为j是循环体里面的一直在变化

        for(j = 0;j<4;j++)
        {
            if(max<p[i][j])
            {
                 max = p[i][j];
                 max_j = j;
            }
        }


        for(k = 0;k<4;k++)
        {
            if(max>p[k][max_j])
            {
                flag = 0;
            }
            else
            {
                continue;
            }
            
        }

        if(flag==1)
        {   
            flag_sum = 1;
            cout<<i<<" "<<max_j<<" "<<max<<endl;
        }
    }

    if(flag_sum==0)
    {
        cout<<"no an_point!"<<endl;
    }
}

int main()
{
    int a[][4] = {1,2,3,10,5,6,7,8,9,10,11,12,13,14,15,5};
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    find_point(a);

    system("pause");
}