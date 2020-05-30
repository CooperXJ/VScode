#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<int> vec;
    vector<int>  G[20];
    vector<int>  seats(20);
    
    fill(seats.begin(),seats.end(),5);

    for(int i =0;i<n;i++)
    {
        int val;
        cin>>val;
        vec.push_back(val);
        //vec[i].push_back(5);
    }

    
    for(int i =1;i<=vec[0];i++)
    {
        G[0].push_back(i);
    }

    //vec[0][1] -= vec[0][0];
    seats[0]-=vec[0];

    for(int i =1;i<n;i++)
    {
        int check = 1;
        for(int j =0;j<20;j++)
        {
            if(vec[i]<=seats[j])
            {
                if(seats[j]!=5)
                {
                    for(int k = 1;k<=vec[i];k++)
                    {
                        G[i].push_back(j*5+k+5-seats[j]);
                    }
                }

                else
                {
                    for(int k = 1;k<=vec[i];k++)
                    {
                        G[i].push_back(j*5+k);
                    }
                }
                //vec[j][1] = vec[j][1] - vec[i][0];
                seats[j] -= vec[i];
                check = 0;   
                break;         
            }
        }
    }
    

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<vec[i];j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
    
}
