#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Person
{
    public:
        Person(string name,int age)
        {
            this->name = name;
            this->age = age;
        }

        bool operator==(const Person &p )const
        {
            return this->name==p.name&&this->age==p.age;
        }

    public:
        int age;
        string name;
};

//find方法
void test0()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it = find(v.begin(),v.end(),3);
    cout<<*it<<endl;

    //二分查找
    cout<<binary_search(v.begin(),v.end(),4)<<endl;
}


//自定义类的find
void test1()
{
    vector<Person> v;
    Person p1("xuejin",23);
    Person p2("xuexia",29);
    v.push_back(p1);
    v.push_back(p2);

    vector<Person>::iterator it = find(v.begin(),v.end(),p2);
    cout<<(*it).name<<" "<<(*it).age<<endl;
}


//adjacent_find 查找是否有相邻相同的元素
void test2()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    vector<int>::iterator it = adjacent_find(v.begin(),v.end());
    cout<<*it<<endl;
}

//find_if  返回第一个满足条件的迭代器
bool compare(int i)
{
    return i>2;
}
void test3()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it = find_if(v.begin(),v.end(),compare);
    cout<<*it<<endl;
}

//count_if  count
void test4()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //返回满足条件的个数
    int num = count(v.begin(),v.end(),3);
    cout<<num<<endl;

    //返回满足条件的迭代器的个数
    num = count_if(v.begin(),v.end(),compare);
    cout<<num<<endl;
}

int main()
{
    test4();
    system("pause");
}