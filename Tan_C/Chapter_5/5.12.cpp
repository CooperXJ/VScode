#include <iostream>
#include <math.h>
using namespace std;

// void get_firstday_peach()
// {
//     for(int i =1;i<=10000;i++)
//     {
//         //由于我的count在这里是整数，因此使用int类型的数据比如1/2=0，因此无法得到正确的结果
//         int count = i;
//         for(int j = 0;j<9;j++)
//         {
//             if(count%2==0)
//             {
//                 count-=((count/2)+1);
//             }
//             else
//             {
//                 break;
//             }           
//         }

//         if(count==1)
//         {
//             cout<<i<<endl;
//         }
//     }
// }

void get_firstday_peach()
{
    int day,x1,x2;
    day = 9;
    x2 = 1;
    while(day>0)
    {
        x1 = (x2+1)*2;//剩下的桃子必须+1才是原来的一半
        x2 = x1;
        day--;
    }
    cout<<x1<<endl;
}

int main()
{
    get_firstday_peach();
    system("pause");
}