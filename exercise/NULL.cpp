#include <iostream>
using namespace std;

class Student
{
    public:
    int id;
    int age;
};

int main()
{
    Student s;
    s.age = 12;
    s.id = 1;
    Student s1 = NULL;
    cout<<s.age<<" "<<s.id;
    system("pause");
}