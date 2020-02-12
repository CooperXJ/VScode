#include <iostream>
#include <math.h>

using namespace std;

//构造pair的三种方法
void test0()
{
    pair<int,int> p(10,20);
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    pair<string,int> p1 = make_pair("薛进",23);
    cout<<p1.first<<endl;
    cout<<p1.second<<endl;

    pair<int,int> p2 = p;
}


int main()
{
    test0();
    system("pause");
}