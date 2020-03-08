#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a[8] = {1,2,3,4,5,6,7,8};  

    int i = 0,j = 0;
    int len = 8;

    while (len!=1)
    {
        //这一步是精髓
        if(a[j]!=0)
            i++;

        if(i==3)
        {
            a[j] = 0;
            len--;
            i = 0;
        }

        //这里千万不能放在最后，因为一旦j=7时，j重置为0相当于是j++了，不需要再j++了
        j++;
        
        if(j==8)//这里是8，而不是7
        {
            j = 0;
        }
    }
    
    for(int i = 0;i<8;i++)
        if(a[i]!=0)
            cout<<a[i]<<endl;
    
    system("pause");
}