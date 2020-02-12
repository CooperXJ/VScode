#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>
using namespace std;


//这里的list是双向链表 
//list不支持随机访问

void print_val(int val)
{
    cout<<val<<" ";
}

//初始化list
void test0()
{
    list<int> l1;
    list<int> l2(6,6);
    list<int> l3(l2);
    list<int> l4(l2.begin(),l2.end());

    for_each(l4.begin(),l4.end(),print_val);
    cout<<endl;
}

//增加、删除
void test1()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    l.push_front(0);
    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    l.insert(l.begin(),-1);
    l.insert(l.end(),4);
    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    l.pop_front();
    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    list<int>::iterator it = l.begin();
    l.erase(l.begin(),++it);
    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    //删除所有和（）中相同的值
    l.push_back(4);
    l.remove(4);
    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

    cout<<l.front()<<endl;//首端

}

bool compare(int a,int b)
{
    return a>b;
}

void test2(){
    list<int> l;
    l.push_back(8);
    l.push_back(2);
    l.push_back(10);

    //l.sort(compare);//list的sort是它内部的成员方法 而不是algorithm中的sort
    //algorithm中的sort只支持可以随机访问的容器进行排序
    l.sort();
    l.reverse();//反转

    for_each(l.begin(),l.end(),print_val);
    cout<<endl;

}


int main()
{
    test2();
    system("pause");
}