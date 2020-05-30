#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int aa[4][3] = {{1,2,3},{5,6,7},{3,9,10},{4,2,9}};
    cout<<aa[0]+2<<endl;
    cout<<aa[0]+1<<endl;

    int i,s1 = 0,s2 = 0;
    for(i=0;i<4;i++)
    {
        s1+=aa[i][1];  //2+6+9+2 = 19
    }
    for(i = 0;i<4;i++)
        s2+=*(aa[i]+2);//3+7+10+9 
    printf("%d\n%d\n",s1,s2);
    system("pause");
}