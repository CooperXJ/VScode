#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> vec;
    int count = 0;

    for(int i =1;i<n;i++)
    {
        vec.push_back(i);
    }
    
    vector<int>::iterator it;
    
    for(it = vec.begin();it<vec.end();it+=1)
    {
        if(it==vec.begin())
            continue;
        vec.erase(it);
    }

     for(it = vec.begin();it<vec.end();it++)
    {
        cout<<*it<<" ";
        if(*it>m)
            count++;
    }
    cout<<endl;

     for(it = vec.begin();it<vec.end();it+=2)
    {
        if(it==vec.begin())
            continue;
        vec.erase(it);
    }
    
     for(it = vec.begin();it<vec.end();it++)
    {
        cout<<*it<<" ";
        if(*it>m)
            count++;
    }
    cout<<endl;


     for(it = vec.begin();it<vec.end();it+=6)
    {
         if(it==vec.begin())
            continue;
        vec.erase(it);
    }

     for(it = vec.begin();it<vec.end();it++)
    {
        cout<<*it<<" ";
        if(*it>m)
            count++;
    }
    cout<<count<<endl;
    system("pause");
}