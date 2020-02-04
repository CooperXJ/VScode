#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void test(){
    ifstream ism("D:\\learning\\code\\C++\\C++_Pro\\file_operation\\source.txt",ios::in);//输入流
    // ifstream ism;
    // ism.open("source.txt",ios::in);

    ofstream osm("D:\\learning\\code\\C++\\C++_Pro\\file_operation\\target.txt",ios::out|ios::app);//输出流
    if(!ism){
        cout<<"open failure"<<endl;
        return;
    }

    char ch;
    while(ism.get(ch))
    {
        cout<<ch;
        osm.put(ch);
    }

    ism.close();

}

class Person{
    public:
        int age;
        string name;

    public:
        Person(){}
        Person(int age,string name)
        {
            this->age = age;
            this->name = name;
        }

        void show()
        {
            cout<<"name:  "<<name<<"  age:  "<<age<<endl;
        }
};

void test1(){
    char *target = "D:\\learning\\code\\C++\\C++_Pro\\file_operation\\target_binary.txt";
    ofstream osm(target,ios::out|ios::binary);

    Person p1(10,"xuejin");
    Person p2(16,"xuexia");

    osm.write((char*)&p1,sizeof(Person));//write(地址，大小)  地址需要强转为char *类型
    osm.write((char*)&p2,sizeof(Person));

    osm.close();
}

void test2(){
    char *source = "D:\\learning\\code\\C++\\C++_Pro\\file_operation\\target_binary.txt";
    ifstream ism(source,ios::in|ios::binary);
    Person p1,p2;
    ism.read((char*)&p1,sizeof(Person));//read(地址，大小) 地址需要强转为char *类型
    ism.read((char*)&p2,sizeof(Person));
    p1.show();
    p2.show();
    
    ism.close();
}

int main()
{
    test1();
    test2();
    system("pause");
}