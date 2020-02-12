#include <iostream>
#include <math.h>
#include <map>
using namespace std;

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

int main()
{
    test0();
    system("pause");
}