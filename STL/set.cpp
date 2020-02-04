#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    set<int>::iterator it;
    it = s.find(3);
    //s.erase(it);
    it = lower_bound(s.begin(),s.end(),3);
    it = upper_bound(s.begin(),s.end(),3)
    cout<<*it<<endl;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    system("pause");
}