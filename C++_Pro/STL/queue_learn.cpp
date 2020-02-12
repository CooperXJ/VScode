#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

void test01()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.back()<<endl;
    
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
    
}
int main()
{
    test01();
    system("pause");
}