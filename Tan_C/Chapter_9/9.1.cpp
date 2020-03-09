#include <iostream>
#include <math.h>
using namespace std;

//直接对结构体进行定义
//此种方式适合用于对结构体进行直接命名，但是只能算是一个变量
struct 
{
   string name;
   int age;
}student{"xuejin",23};

//定义结构体数组
struct
{
    string name;
    int age;
}stu[3];

struct Student
{
    string name;
    int age;
};

//typedef 相当于是对结构体进行取别名
typedef struct{
    string name;
    int age;
}Stud;

int main()
{
    // cout<<student.name<<endl;
    // cout<<student.age<<endl;
    // stu[0].name = xuejin;
    // stu[0].age = 23;

    //定义结构体数组方式2
    // struct Student stu[2];    

    // Stud stu;
    // stu.name = "xuejin";
    // stu.age = 23;
    // cout<<stu.name<<endl;
    // cout<<stu.age<<endl;

    struct Student stu;
    
    system("pause");
}