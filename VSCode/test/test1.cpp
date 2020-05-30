#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    //getline(cin,s);
    s = "summon123";
    //cout<<s.find("summon")<<endl;
    if(s.find("summon")!=string::npos)
    {
        cout<<"Yes"<<endl;
    }

    else if(s.find("4"))
    {
        cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}
