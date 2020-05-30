#include <iostream>
#include <math.h>
using namespace std;

void f(int (*a)[5])
{
    int i,j;
    int x = 0;
    int y = 0;

    int flag = 1;
    int final_flag = 0;
    for(i =0;i<4;i++)
    {
        //每次找完一行之后就自动更新flag的值，否则flag的值迟迟不会更新
        flag = 1;

        //找出某一行的最大值
        int max = a[i][0];
        for(j =1;j<5;j++)
        {
            if(max<a[i][j])
            {
                max = a[i][j];
                y = j;
            }
        }

        for(j=0;j<4;j++)
        {
            if(max>a[j][y])
            {
                flag = 0;
                break;
            }
        }

        if(flag==1)
        {
            cout<<i<<" "<<y<<endl;
            final_flag = 1;
        }
    }

    if(final_flag==0)
    {
        cout<<"no point!"<<endl;
    }
}

int main()
{
    int a[][5] = {1,2,3,4,11,2,4,6,8,10,3,6,9,12,15,4,8,12,16,7};
    f(a);
    system("pause");
}