#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> intMap;
    intMap.insert(pair<int,int>(1,2));
    intMap.insert(pair<int,int>(2,3));
    intMap.insert(pair<int,int>(3,4));
    intMap.insert(pair<int,int>(5,6));
    
    map<int,int>::iterator strmap_iter = intMap.begin();
    for(;strmap_iter !=intMap.end();strmap_iter++)
    {
        cout<<strmap_iter->first<<' '<<strmap_iter->second<<endl;
    }
    cout<<endl;
    strmap_iter = intMap.find(3);
    cout<<strmap_iter->first<<","<<strmap_iter->second<<endl;
    strmap_iter = intMap.end();
    cout<<strmap_iter->first<<","<<strmap_iter->second<<endl;
    strmap_iter = intMap.upper_bound(2);
    cout<<strmap_iter->first<<","<<strmap_iter->second<<endl;
    system("pause");
}