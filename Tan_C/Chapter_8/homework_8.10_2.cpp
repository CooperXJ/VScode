#include <iostream>
#include <math.h>
using namespace std;


//直接使用指针可以直接交换数据到对方的地址
void change(int *p)
{
    int *pmin,*pmax;
    pmin = p;
    pmax = p;

    for(int i =0;i<5;i++)
    {
        for(int j =0;j<5;j++)
        {
            if(*pmax<*(p+5*i+j))
                pmax = p+5*i+j;
            if(*pmin>*(p+5*i+j))
                pmin = p+5*i+j;
        }
    }

            //交换最大值
            int t = *(p+12);
            *(p+12) = *pmax;
            *pmax = t;

            //交换最小值
            t = *p;
            *p = *pmin;
            *pmin = t;

            //第一小的不参与竞争
            pmin = p+1;

            //交换第二小的 
            for(int i =0;i<5;i++)
            {
                for(int j =0;j<5;j++)
                {
                    if(((p+5*i+j)!=p)&&(*pmin>*(p+5*i+j)))
                        pmin = p+5*i+j;
                }
            }

            t = *pmin;
            *pmin = *(p+4);
            *(p+4) = t;

            pmin = p+1;

             //交换第三小的 
            for(int i =0;i<5;i++)
            {
                for(int j =0;j<5;j++)
                {
                    if(((p+5*i+j)!=p)&&(*pmin>*(p+5*i+j))&&((p+5*i+j)!=(p+4)))
                        pmin = p+5*i+j;
                }
            }

            t = *pmin;
            *pmin = *(p+20);
            *(p+20) = t;

            pmin = p+1;

             //交换第四小的 
            for(int i =0;i<5;i++)
            {
                for(int j =0;j<5;j++)
                {
                    if(((p+5*i+j)!=p)&&(*pmin>*(p+5*i+j))&&((p+5*i+j)!=(p+4))&&((p+5*i+j)!=(p+20)))
                        pmin = p+5*i+j;
                }
            }

            t = *pmin;
            *pmin = *(p+24);
            *(p+24) = t;
}


int main()
{

    int a[][5] = {35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11};
    change(&a[0][0]);
    for(int i =0;i<5;i++)
    {
        for(int j =0;j<5;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //对于&arr[0][0]与arr的区别的理解
    int arr[][2] = {1,2,3,4,5,6};
    //相当于提供了二维数组的入口
    int *p = &arr[0][0];
    cout<<*(p+1)<<endl;
    int (*p1)[2] = arr;
    cout<<p1<<endl;
    // for(int i =0;i<3;i++)
    // {
    //     for(int j = 0;j<2;j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }

    // //虽然两者地址一样但是有着不同的含义，p指向的是二维数组中的第一个元素的地址，P1指向的是第一行元素的首地址
    // int *p = &arr[0][0];
    // int (*p1)[2] = arr;

    
    // int t = *(p+1);//正确 t表示的是第二个元素的地址
    // int t1 = *(*(p1+1)+1);//错误，因为t1表示的是第二行的地址

    // cout<<t<<endl;
    // cout<<t1<<endl;
    // *(p+1) = *p;
    // *p = t;

    // for(int i =0;i<3;i++)
    // {
    //     for(int j = 0;j<2;j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }


    system("pause");
}