#include <iostream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;
#define research 1
#define sale  2
#define accout 3

class Employee
{
    public:
        Employee(){

        }
        Employee(string name,int age,int groupID):name(name),age(age),groupID(groupID){

        }
        ~Employee()
        {

        }

    public:
        string name;
        int age;
        int groupID;
};

void CreateEmployee(vector<Employee> &e)
{
    string nameseed = "ABCDE";
    for(int i =0;i<5;i++)
    {
        Employee em;
        em.name = "Employee ";
        em.name+=nameseed[i];
        em.age = rand()%10+20;

        e.push_back(em);
    }
}

void EmployeeByGroup(vector<Employee> &e,multimap<int,Employee> &employeeGroup)
{
    for(vector<Employee>::iterator it = e.begin();it!=e.end();it++)
    {
        int ID = rand()%3+1;
        switch (ID)
        {
        case research:
            (*it).groupID = research;
            break;
        case sale:
            (*it).groupID = sale;
            break;
        case accout:
            (*it).groupID = accout;
            break;
        default:
            break;
        }

        employeeGroup.insert(make_pair(ID,*it));
    }
}

void PrintEmployee(multimap<int,Employee> employeeGroup)
{
    cout<<"Group:research: "<<endl;
    multimap<int,Employee>::iterator it = employeeGroup.find(research);
    //count的作用是寻找key一样的元素个数
    int count = employeeGroup.count(research);

    //  C/C++不能在同一条语句中定义不同类型的变量   除非用;分割
    //因此i和j不能放到同一句中定义;
    int j = 0;
    for(multimap<int,Employee>::iterator i = it;j<count;i++,j++)
    {
        cout<<"Group: "<<i->first<<" name: "<<(i->second).name<<" age: "<<(i->second).age<<endl;
    }

    cout<<"Group:sale "<<endl;
    it = employeeGroup.find(sale);
    count = employeeGroup.count(sale);

    j = 0;
    for(multimap<int,Employee>::iterator i = it;j<count;i++,j++)
    {
        cout<<"Group: "<<i->first<<" name: "<<(i->second).name<<" age: "<<(i->second).age<<endl;
    }

    cout<<"Group:accout "<<endl;
    it = employeeGroup.find(accout);
    count = employeeGroup.count(accout);

    j = 0;
    for(multimap<int,Employee>::iterator i = it;j<count;i++,j++)
    {
        cout<<"Group: "<<i->first<<" name: "<<(i->second).name<<" age: "<<(i->second).age<<endl;
    }
}

int main()
{
    vector<Employee> e;
    multimap<int,Employee> employeeGroup;

    CreateEmployee(e);
    EmployeeByGroup(e,employeeGroup);
    PrintEmployee(employeeGroup);
    system("pause");
}