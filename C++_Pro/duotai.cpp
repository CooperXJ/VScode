#include <iostream>
#include <math.h>
using namespace std;

class Animal{
    public:
        virtual void bark()
        {
            cout<<"This is animal"<<endl;
        }
};

class Cat:public Animal {
    public:
        void bark()
        {
            cout<<"miao~"<<endl;
        }
};

int main()
{
    Animal *a = new Cat();
    a->bark();
    system("pause");
}