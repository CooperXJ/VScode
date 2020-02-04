#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    map<int,int> pair1;

    int count = 0;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    sort(vec.begin(),vec.end());
    for(int i =0;i<vec.size();i++)
    {
        for(int j =i;j<vec.size();j++)
        {
            if(vec[i]==vec[j])
                continue;
            else
            {
                cout<<vec[i]<<" "<<vec[j]<<endl;
            }
        }
    }

    
    
    system("pause");
}