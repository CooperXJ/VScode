#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

//set底层是红黑树

class Person
{
    public:
        Person(string name,int age):name(name),age(age){}
        ~Person(){}

    public:
        string name;
        int age;
};

//仿函数
class Mycompare
{
    public:
        bool operator()(int v1,int v2){
            return v1>v2;
        }
};

class Mycompare1
{
    public:
        bool operator()(Person p1,Person p2)
        {
            return p1.age>p2.age;
        }
};

void print_val(int i)
{
    cout<<i<<" ";
}

void print_person(Person p)
{
    cout<<p.name<<" "<<p.age<<endl;
}


void test0()
{
    set<int> s;
    s.insert(2);
    s.insert(10);
    s.insert(11);
    s.insert(5);
    s.insert(5);//重复的数值会被省略

    for_each(s.begin(),s.end(),print_val);
    cout<<endl;

    //删除
    s.erase(s.begin());
    s.erase(5);
    for_each(s.begin(),s.end(),print_val);
    cout<<endl;

    set<int>::iterator it = s.find(10);//查找

    if(it!=s.end())
        cout<<*it<<endl;

    it = s.lower_bound(10);//返回第一个>=（）中的指针
    cout<<*it<<endl;

    it = s.upper_bound(10);//返回第一个>（）中的指针
    cout<<*it<<endl;

    //返回pair  返回值是lower_bound 和 upper_bound的指针
    pair<set<int>::iterator,set<int>::iterator> p= s.equal_range(10);
    cout<<*(p.first)<<endl;
    cout<<*(p.second)<<endl;
}

//利用仿函数将set从大到小排列
void test1()
{
    set<int,Mycompare> s;
    s.insert(2);
    s.insert(10);
    s.insert(11);
    s.insert(5);


    for_each(s.begin(),s.end(),print_val);
    cout<<endl;
}

void test2()
{
    //set<Person> s;//如果直接这样写的话会出现问题  因为set会排序，但是这是一个对象无法知道排序的标准，因此无法插入

    set<Person,Mycompare1> s;
    Person p1("张三",10),p2("李四",11),p3("王五",12);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for_each(s.begin(),s.end(),print_person);
    cout<<endl;

    set<Person>::iterator it = s.find(p1);
    cout<<(*it).name<<endl;

    //此处会输出王五 是因为这里set是根据Mycompare1中指定的排序规则来寻找的
    //张三和赵六的age是一样的，因此他会默认只招 age=10 的Person对象  所以会出现找到的情况
    Person p("赵六",10);
    it = s.find(p);
    cout<<(*it).name<<endl;

}

int main()
{
    test2();
    system("pause");
}