#include <iostream>
#include <math.h>
#include <map>
using namespace std;

class myMap
{
    public:
    myMap(int key,int ID)
    {
        this->key = key;
        this->ID = ID;
    }

    bool operator < (const myMap &m1) const//如果下面的结构体不写的话  就必须要写这个  并且两个const是必须的
    {
        return this->key < m1.key;
    }


    public:
        int key;
        int ID;
};

//初始化map
void test0()
{
    map<int,int> m1;
    m1.insert(pair<int,int>(10,10));

    m1.insert(make_pair(20,20));

    m1.insert(map<int,int>::value_type(30,30));

    // 如果key存在，则此种方式访问修改key对应的value
    //如果key不存在，则此种方式创建pair插入到map容器中
    m1[40] = 40;

    for(map<int,int>::iterator it = m1.begin();it!=m1.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    
    m1[10] = 100;
    cout<<m1[10]<<endl;

    //不会报错，会默认的创建一个key=100，value=0的pair到map容器中
    cout<<m1[100]<<endl;
}

//因为不知道myMap的排序顺序，所以不能够插入，因为map也是按照键来排序的
//如果在类中不重载 < ,可以在此处用结构体重载 <
struct compare
{
    bool operator()(myMap m1,myMap m2)
    {
        return m1.key<m2.key;
    }
};

//Map的进阶操作
void test1()
{
    myMap m1(1,2);
    myMap m2(2,4);
    myMap m3(3,4);
    map<myMap,int> m;

    m.insert(make_pair(m1,1));
    m.insert(make_pair(m2,2));
    m.insert(make_pair(m3,3));

    for(map<myMap,int>::iterator it = m.begin();it!=m.end();it++)
    {
        cout<<(*it).first.key<<" "<<(*it).first.ID<<" "<<(*it).second<<endl;
    }
}

int main()
{
    test1();
    myMap m(1,2);
    myMap m1(2,3);
    cout<<(m<m1)<<endl;

    system("pause");
}