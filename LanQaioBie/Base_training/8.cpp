#include <iostream>
using namespace std;

int main()
{
    for(int i = 1;i<10;i++)
    {
        for(int j =0;j<10;j++)
        {
            for(int k = 0;k<10;k++)
            {
                for(int l = 1;l<10;l++)
                {
                    if(i==l&&j==k)
                    {
                        cout<<i<<j<<k<<l<<endl;
                    }
                }
            }
        }
    }
    system("pause");
}