#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;

    vector<string> vec;
    vector<int> v;
    for(int i =0;i<M;i++)
    {
        string res;
        cin>>res;
        vec.push_back(res);
        v.push_back(res.length());
    }

    
}