#include <iostream>
using namespace std;

template <class T1,class T2>
T2 add(T1 t1,T2 t2)
{
    return t1+t2;
}

template <class T>
class Person{
    public:
        Person(T name,T age)
        {
            this->name = name;
            this->age = age;
        }

        void show();

    public:
        T name;
        T age;
};

template <class T>//模板类外声名类内成员函数
void Person<T>::show(){
    cout<<name<<"  "<<age<<endl;
}

int main()
{
    //cout<<add(1,1.5)<<endl;
    Person<int> p(10,20);
    p.show();

    system("pause");
}