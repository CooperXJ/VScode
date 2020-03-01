#include "Person.h"
Person::Person(string name,int age){
    this->name = name;
    this->age = age;
}

void Person::show(){
    cout<<"Name: "<<this->name<<" Age： "<<this->age<<endl;
}
