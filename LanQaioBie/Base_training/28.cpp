#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    int res = 0;
    int n;
    cin>>n;

    int cost = 0;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

   
    while(vec.size()!=1)
    {
        cost = 0;
        vector<int>::iterator it_min1 = std::min_element(vec.begin(),vec.end());
        cost += *it_min1;
        vec.erase(it_min1);

        vector<int>::iterator it_min2 = std::min_element(vec.begin(),vec.end());
        cost += *it_min2;
        vec.erase(it_min2);

        vec.push_back(cost);
        res+=cost;
    }

    cout<<res<<endl;
    system("pause");
}