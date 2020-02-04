#include <iostream>
using namespace std;


int main()
{
    for(int k =0;k<32;k++)
    {
        int i,j=0;
        int a[1000] = {0};
        i=k;
        while(i)
            {
            a[j]=i%2;
            i/=2;
            j++;
    
            }

    
            for(i=4;i>=0;i--)
                cout<<a[i];
            cout<<endl;

    }
   
    
    system("pause");
}
