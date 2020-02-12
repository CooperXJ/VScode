#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

void test01()
{
    //不能遍历 不提供迭代器
   stack<int> s;
   //增加元素
   s.push(1);
   s.push(2);
   s.push(3);

   cout<<s.top()<<endl;//通过top来访问元素

    //删除元素
    s.pop();
    cout<<s.top()<<endl;

    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}

int main()
{
    test01();
   system("pause");
}