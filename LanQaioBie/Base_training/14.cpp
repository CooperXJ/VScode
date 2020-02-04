#include <iostream>
using namespace std;

int main()
{
    int time;
    cin>>time;

    int h,m,s;
    h = time/3600;
    m = (time - 3600*h)/60;
    s = (time - h*3600 - m*60);
    cout<<h<<":"<<m<<":"<<s<<endl;
    system("pause");
}