#include <iostream>
#include <iomanip>//添加大写
using namespace std;

int main()
{
    int num;
    cin>>num;
    cout<<setiosflags(ios::uppercase)<<hex<<num<<endl;
    system("pause");
    return 0;
}