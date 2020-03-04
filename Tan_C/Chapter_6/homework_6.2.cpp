#include <iostream>
#include <math.h>
using namespace std;

void choose_sort(int *arr)
{
    for(int i =0;i<6;i++)
    {
        int min = i;
        for(int j = i+1;j<6;j++)
        {
            //将索引作为比较数字的替代
            if(arr[min]>arr[j])
                min = j;
        }
        //最终确定了再交换  这里也是和冒泡排序的区别之一
        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
    for(int i =0;i<6;i++)
        cout<<arr[i]<<endl;
}

int main()
{
    int a[] = {3,2,1,5,7,6};
    choose_sort(a);
    system("pause");
}