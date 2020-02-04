#include <iostream>
#include <string>
using namespace std;

int main()
{
    string res = "123";
    res[res.size()-1] = NULL;
    cout<<res<<endl;
    cout<<2/2<<endl;
    for(int i =0;i<10;i++)
    {
        if(i>5)
        {
            if(i==6)
            cout<<i<<endl;
            break;
        }
    }
    system("pause");
}