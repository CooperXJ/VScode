#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

//函数对象
/*
    1.函数对象可以像普通函数一样使用
    2.函数对象可以像普通函数那样接收参数
    3.函数对象超出函数的概念，函数对象可以保存函数调用的状态
    比如我下面结构体中的num可以体现出函数调用的次数
*/
struct MyPrint
{
    void operator()(int i)
    {   
        cout<<i<<endl;
        num++;
    } 

    public:
        int num = 0;
};


void test0()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    MyPrint m1;

    MyPrint m2 = for_each(v.begin(),v.end(),m1);
    //下面m2才是调用的次数，因为for_each是将函数复制了一份，因此m2才是for_each真正调用的函数，而m1并没有调用
    cout<<m1.num<<endl;
    cout<<m2.num<<endl;
}

int main()
{
    // MyPrint m;
    // m(10);
    // cout<<m.num<<endl;

    test0();
    system("pause");
}