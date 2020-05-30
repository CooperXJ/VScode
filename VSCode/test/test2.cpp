#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(1);

    vector<int>::iterator it  = find(vec.begin(),vec.end(),1);

    cout<<*it<<endl;
    system("pause");
}
