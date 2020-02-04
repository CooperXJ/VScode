#include <iostream>
using namespace std;

int main()
{
    int row;
    cin>>row;

    row+=1;

    int triangle[35][35] = {0};//二维数组的巧妙运用
    
    triangle[1][1] = 1;
    triangle[2][1] = 1;
    triangle[2][2] = 1;
    for(int i =3;i<row;i++)
    {
        for(int j =0;j<row;j++)
        {
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
        }
    }

    int flag = 0;
    for(int i =1;i<35;i++)
    {
        flag  =0;
        for(int j =1;j<35;j++)
        {
            if(triangle[i][j]!=0)
            {
                flag = 1;
                cout<<triangle[i][j]<<" ";
            }
        }

        if(flag)
        cout<<endl;
    }
    system("pause");
}