#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

int main()
{
    double  x1,y1,x2,y2;
    double  x3,y3,x4,y4;
    cin>>x1>>x2>>y1>>y2;
    cin>>x3>>x4>>y3>>y4;
    double m1 = max(min(x1,x2),min(x3,x4)); 
    double m2 = min(max(x1,x2),min(x3,x4));
    double n1 = max(min(y1,y2),min(y3,y4));
    double n2 = min(max(y1,y2),max(y3,y4));

    if(m1<m2&&n1<n2)
    {
        double area = (m2-m1)*(n2-n1);
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<area<<endl;
    }
    else
    {
        cout<<"0.00"<<endl;
    }
    system("pause");
    return 0;
    
}