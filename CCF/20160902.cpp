#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> vec[20];
    vector<int>  G[20];
    for(int i =0;i<n;i++)
    {
        int val;
        cin>>val;
        vec[i].push_back(val);
        vec[i].push_back(5-val);
    }

    for(int i =0;i<n;i++)
    {
        bool flag = false;
        int j;
        for( j =0;j<=i;j++)
        {
            if(vec[i][0]<=vec[j][1]&&i!=j)
            {
                for(int k = 1;k<=vec[i][0];k++)
                {
                    G[i].push_back(j*5+k+vec[i-1][0]);
                    vec[j][1] = vec[j][1]-vec[i][0];
                }
                flag = true;
                break;
            }
        }
		
		if(!flag)
		{
			for(int i =1;i<=vec[i][0];i++)
			{
				G[i].push_back(j*5+i);
			}
		} 
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<vec[i][0];j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
    
}

