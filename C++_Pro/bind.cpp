#include <iostream>
#include <math.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


//bind的作用就是将2个参数绑定为一个参数传入
//例如本例中的for_eac的函数最后只需要一个参数，但是现在可以通过bind来绑定2个参数使其成为一个参数
class Person
{
    public:
        Person(string name,int age):name(name),age(age)
        {

        }

        void show()
        {
            cout<<name<<" "<<age<<endl;
        }

    private:
        string name;
        int age;
};

struct MyPrint:public binary_function<int,int,void>
{
    void operator()(int i,int val) const
    {
        cout<<i+val<<" "<<i<<" "<<val<<endl;
    }
};

struct bigger5:public unary_function<int,bool>
{
    bool operator()(int i) const
    {
        return i>5;
    }
};

void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    int addnum = 100;
    //bind1st是是得i成为绑定的对象，本例中为100  说到底就是将addnum赋值给i还是val
    for_each(v.begin(),v.end(),bind1st(MyPrint(),addnum));

    //bind2nd是是得val成为绑定的对象，本例中为100
    for_each(v.begin(),v.end(),bind2nd(MyPrint(),addnum));
}

//取反适配器
//not1是一元
//not2是二元
void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>::iterator it = find_if(v.begin(),v.end(),not1(bigger5()));
    cout<<*it<<endl;
}

//类中方法的调用
//mem_fun_ref
//mem_fun
void test2()
{
    //存放的是使用的对象
    Person p1("xueijn",23),p2("xuexia",29);
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    for_each(v.begin(),v.end(),mem_fun_ref(&Person::show));

    cout<<endl;

    //存放的是对象指针
    vector<Person*> v1;
    v1.push_back(&p1);
    v1.push_back(&p2);
    for_each(v1.begin(),v1.end(),mem_fun(&Person::show));
}


void Print(int i,int j)
{
    cout<<i+j<<endl;
}

//ptr_fun  将函数转为函数对象
void test3()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for_each(v.begin(),v.end(),bind2nd(ptr_fun(Print),100));
}

int main()
{
    // test();
    // test1();
    //test2();
    test3();
    system("pause");
}