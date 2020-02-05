#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(int val)
{
    cout<<val<<" ";
}

void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //容器的迭代器  这里指定类型是因为每种数据类型++或者--不同
    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    //容器中可能存放基础的数据类型，也可能存放用户自定义的类型
    //因此需要自己提供打印的方法
    for_each(pBegin,pEnd,print_vector);
}

int main()
{
    test();
    system("pause");
}