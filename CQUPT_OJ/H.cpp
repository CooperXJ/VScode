#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int,int> intMap;

    vector<int> vec;
    vector<int> vec_p;
    for(int i =0;i<n;i++)
    {
        int m;
        cin>>m;
        intMap.insert(pair<int,int>(m,i+1));
    }

    map<int,int>::iterator strmap_iter = intMap.begin();
    for(;strmap_iter !=intMap.end();strmap_iter++)
    {
       vec.push_back(strmap_iter->second);
    }

    

    for(int i =0;i<n;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    

    for(int i =0;i<n;i++)
    {
        int t = upper_bound(vec.begin(),vec.end(),i+1) - vec.begin();
        if(t>=n)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<vec[t]<<" ";
        }
        
    }

    
   
    system("pause");
}