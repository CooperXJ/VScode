#include <iostream>
#include <math.h>
using namespace std;

int arr[] = {1,2,4,1,7,8,3};
int arr_save[7] = {0};

int dp(int i)
{
    if(i==0)
        return arr[0];
    else if(i==1)
        return arr[0]>arr[1]?arr[0]:arr[1];
    else
    {
        int A = arr[i]+dp(i-2);
        int B = dp(i-1);

        return A>B?A:B;
    }  
}

int dp_opt()//使用数组保存已有的值  非递归
{
    arr_save[0] = arr[0];
    arr_save[1] = arr[0]>arr[1]?arr[0]:arr[1];

    for(int i =2;i<7;i++)
    {
        int A = arr_save[i-2]+arr[i];
        int B = arr[i-1];
        arr_save[i] = A>B?A:B;
    }

    return arr_save[6];
}

int main()
{
    cout<<dp(6)<<endl;
    cout<<dp_opt()<<endl;
    system("pause");
}