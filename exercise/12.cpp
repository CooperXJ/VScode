#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(9);

    int t = upper_bound(vec.begin(),vec.end(),7) - vec.begin();
    cout<<t<<endl;

    vector<int>::iterator it = vec.begin()+2;
     for(;it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    system("pause");
}