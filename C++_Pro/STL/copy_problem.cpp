#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

class Person
{
    public:
        Person(char* name,int age)
        {
            this->name = new char[strlen(name)+1];//这里new了对象 因此需要释放掉
            strcpy(this->name,name);
            this->age = age;
        }

        Person (const Person &p)//拷贝构造函数  如果我们不写的话  系统会帮我们编写  但是仅仅是简单的赋值操作 但是我们在写了析构函数之后就会释放掉空间
        //从而导致vector内部的Person对象指针没有了指向的字符串，所以会出错，因此我们需要深拷贝
        {
            this->name = new char[strlen(p.name)+1];
            strcpy(this->name,p.name);
            this->age = p.age;
        }

        Person& operator = (const Person &p)
        {   
            if(this->name!=NULL)
                delete[] this->name;
            
            this->name = new char[strlen(p.name)+1];
            strcpy(this->name,p.name);
            this->age = p.age;

            return *this;
        }

        //析构函数是在main函数结束之后调用的
        ~Person()
        {
            delete[] this->name;
            //system("pause");
        }

    public:
        int age;
        char *name;
};

int main()
{
   

    Person p("xuejin",23);
    vector<Person> v;
    v.push_back(p);
    cout<<v[0].name<<endl;
    
}