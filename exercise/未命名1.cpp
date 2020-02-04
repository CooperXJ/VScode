#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int *vec =(int*)malloc(sizeof(int)*n);
    //vector<int> vec;

    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        //vec.push_back(m);
        vec[i] = m;
    }

    //vector<int>::iterator it = vec.begin();
    for(int i=0;i<n;i++)
    {
        int it = upper_bound(vec+i,vec+n,vec[i]) - vec;
        if(it>=n||it<i)
        {
            //cout<<"i "<<i<<"it "<<it<<"|| ";
            cout<<-1<<" ";
        }
        else
        {
            cout<<it+1<<" ";
        }
        
        
    }

    system("pause");

}