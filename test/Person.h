#include <iostream>
#include <string>
#pragma once //防止头文件重复

using namespace std;

class Person{
    public:
        Person(string name,int age);

        void show();
    public:
        string name;
        int age;
};