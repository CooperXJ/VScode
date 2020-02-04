#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double heigt = 100;
    for(int i =0;i<10;i++)
    {
        double drop_height = 100;
        for(int j =0;j<=i;j++)
        {
            drop_height/=2.0;
        }
        cout<<"下降高度 = "<<drop_height<<endl;
        heigt-=drop_height;
    }

    cout<<heigt<<endl;
    cout<<(2<sqrt(5))<<endl;
    system("pause");
}