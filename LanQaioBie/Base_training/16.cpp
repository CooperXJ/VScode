#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(int number)
{
    int flag = 0;
    for(int i =2;i<number;i++)
    {
        if(number%i==0&&number!=2)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main()
{
    int a,b;
    cin>>a>>b;

    vector<int> odd;

    for(int i =2;i<=b;i++)
    {
        if(!check(i))
        {
            odd.push_back(i);
        }
    }

    for(int n =a;n<=b;n++)
    {
        for(int j =0;j<odd.size();j++)
        {
            int i = n;
            if(i%odd[j]==0)
            {
                if(i==odd[j])
                {
                    cout<<i<<"="<<odd[j];
                    break;
                }
                else
                {
                    cout<<i<<"="<<odd[j]<<"*";
                    i/=odd[j];
                    int m = 1;
                    int k =i;
                    //cout<<"k   "<<k<<endl;
                    while(i!=1&&m<=k){
                         i/=odd[j];
                         //cout<<"i  "<<i<<endl;
                         m*=odd[j];
                         cout<<odd[j]<<"*";
                    }

                    if(i==1)
                    {
                        break;
                    }    
                }
            }
        }
        cout<<endl;
    }


    system("pause");
    return 0;
}