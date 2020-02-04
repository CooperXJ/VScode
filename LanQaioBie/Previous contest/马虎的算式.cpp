#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    for(int i=1;i<10;i++)
    {
        for(int j =1;j<10;j++)
        {
            for(int k =1;k<10;k++)
            {
                for(int l = 1;l<10;l++)
                {
                    for(int m = 1;m<10;m++)
                    {
                        if(i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m)
                        {
                        if((i*10+j)*(k*100+l*10+m)==(i*100+l*10+j)*(k*10+m))
                        {
                            count++;
                        }
                        }
                    }
                }
            }
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}