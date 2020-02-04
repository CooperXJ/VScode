#include <iostream>
using namespace std;

int main()
{
    int a[3000] = {0};//最主要的就是初始化都为0  那样循环的时候就可以不用考虑此刻的数组长度
                    //都循环一遍就行了
    a[0] = 1; 
    int c = 0;
    int s = 0;
    int n;
    cin>>n;

    for(int i =2;i<=n;i++)
    {
        for(int j =0;j<3000;j++)
        {
            s = a[j]*i+c;
            a[j] = s%10;
            c = s/10;//此处最重要  
        }
    }

    int i;
    for(i = 3000-1;i>=0;i--)
    {
        if(a[i])
        break;
    }

    for(int j=i;j>=0;j--)
    {
        cout<<a[j];
    }

    system("pause");
    return 0;
}