#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    for(int i =1;i<10;i++)
    {
       for(int j =0;j<10;j++)
       {
           for(int k =0;k<10;k++)
           {
               int res = pow(i,3)+pow(j,3)+pow(k,3);
                if(res==(i*100+j*10+k))
                cout<<i<<j<<k<<endl;
           }
       }
    }
    system("pause");
}
