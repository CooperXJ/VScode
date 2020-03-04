#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    for(int i ='x';i<='z';i++)
    {
        for(int j ='x';j<='z';j++)
        {
            for(int k = 'x';k<='z';k++)
            {
                if(i!=j&&i!=k&&j!=k&&i!='x'&&k!='x'&&k!='z')
                   printf("A--%c B--%c  C--%c\n",i,j,k);
            }
        }
    }
    system("pause");
}