#include <stdio.h>

//因为这里是使用g++编译的，g++是编译 C++的，C++在使用结构体的时候可以直接像类一样访问，C的话必须使用struct test t1  必须前缀名加上struct
struct test
{
    int age;
};

test t;

int main()
{
    test t[2];
    test t1;
    t[0].age = 10;
    t[1].age = 20;
    t1.age = 22;
    printf("%d\n",t[0].age);
    printf("%d\n",t[1].age);
    printf("%d\n",t1.age);
    getchar();
}