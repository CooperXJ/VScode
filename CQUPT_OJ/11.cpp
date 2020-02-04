#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    vector<int> vec; 
    for(int i =0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        vec.push_back(m);
    }

    int flag;
    for(int i =0;i<n;i++)
    {
        flag = 0;
        for(int j =i+1;j<n;j++)
        {
            
            if(vec[i]<vec[j])
            {
                cout<<j+1<<" ";
                flag = 1;
                break;
            }
            
        }

        if(!flag)
        {
            cout<<-1<<" ";
        }
    }
    system("pause");
}