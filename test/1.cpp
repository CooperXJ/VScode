#include <iostream>
#include "Person.h"
using namespace std;


template <typename T>

T square(T x)
{
    return x*x;
}

// template <class T>
// class Person{
//     public:
//         Person(T id,T age)
//         {
//             this->age = age;
//             this->id = id;
//         }

//         void show()
//         {
//             cout<<id<<" "<<age<<endl;
//         }
//     public:
//         T id;
//         T age;
// };

template <class T>
class Animal{
    public:
    void jiao()
    {
        cout<<"我在叫！"<<endl;
    }

    public:
        T age;
};

class Cat:public Animal<int>{
    
};

void test()
{
    // Person<int> p(10,20);//必须要显式出类型
    // p.show(); 
    Person p("xuejin",22);
    p.show();
}
    
int main()
{
    cout<<square<int>(5)<<endl;
    cout<<square<double>(5.5)<<endl;
    //test();
    system("pause");
}
