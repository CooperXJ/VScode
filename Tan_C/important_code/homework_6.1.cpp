#include <iostream>
#include <math.h>
using namespace std;

void f(int number)
{
   int arr[101];
   for(int i =1;i<=100;i++)
        arr[i] = i;

   //先删除arr[1],因为1是所有的数的因子，但是他本身不是素数
   arr[0] = 0;
   arr[1] = 0;
   for(int i =1;i<sqrt(100);i++)//这里将i作为除数只需要到达sqrt（1000）即可，因为如果超过这个都没有因子，那么不可能还存在其他的因子
   {
       for(int j =i+1;j<=100;j++)//从arr[i]开始向后查找看是否有arr[i]的倍数，如果有就删除
       {
           if(arr[i]!=0&&arr[j]!=0)
           {
               if(arr[j]%arr[i]==0)
               {
                   arr[j]=0;
               }
           }
       }
   }

   for(int i = 0;i<=100;i++)
   {
       if(arr[i]!=0)
        cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main()
{

    f(1000);
    system("pause");
}