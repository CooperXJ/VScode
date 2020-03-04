#include <iostream>
#include <math.h>
using namespace std;

int sum_of_n_a(int a,int count)
{
    int res = 0;
    for(int i = 1;i<=count;i++)
    {
        int n = 0;
        for(int j =0;j<i;j++)
        {
            double add = pow(10,j)*a;//这里必须要声明为double否则会精度丢失成为199
            n=n+add;
        }
        cout<<n<<endl;
        res+=n;
    }
    return res;
}

int main()
{
    cout<<sum_of_n_a(2,5)<<endl;
    system("pause");
}