#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool compare(vector<int> v1,vector<int> v2)
{
    return v1[0]<v2[0];
}

void f(int (*a)[5])
{
    vector<int> v;
    int k = 0;
    for(int i =0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
          v.push_back(a[i][j]);
        }
    }

    sort(v.begin(),v.end());

    vector< vector<int> > vec;

    for(int i =0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(a[i][j]==v[0]||a[i][j]==v[1]||a[i][j]==v[2]||a[i][j]==v[3]||a[i][j]==v[24])
            {
                vector<int> v;
                v.push_back(a[i][j]);
                v.push_back(i);
                v.push_back(j);
                vec.push_back(v);
            }
        }
    }
    
   sort(vec.begin(),vec.end(),compare);


    if(a[0][0]!=vec[0][0])
    {
        int t = a[0][0];
        a[0][0] = vec[0][0];
        int i =vec[0][1];
        int j =vec[0][2];

        a[i][j] = t;

        //这里一定要注意，因为有可能被替换的那个数就是最小值中的一个，因此需要记录一下如果被替换的数是这种情况的话，重新更新后的位置是什么
        for(int i =0;i<5;i++)
        {
            if(t==vec[i][0])
            {
                vec[i][1] = i;
                vec[i][2] = j;
            }
        }
    }

    if(a[0][4]!=vec[1][0])
    {
        int t = a[0][4];
        a[0][4] = vec[1][0];
        int i =vec[1][1];
        int j =vec[1][2];

        a[i][j] = t;

        for(int i =0;i<5;i++)
        {
            if(t==vec[i][0])
            {
                vec[i][1] = i;
                vec[i][2] = j;
            }
        }
    }

    if(a[4][0]!=vec[2][0])
    {
        int t = a[4][0];
        a[4][0] = vec[2][0];
        int i =vec[2][1];
        int j =vec[2][2];

        a[i][j] = t;

        for(int i =0;i<5;i++)
        {
            if(t==vec[i][0])
            {
                vec[i][1] = i;
                vec[i][2] = j;
            }
        }
    }

    if(a[4][4]!=vec[3][0])
    {
        int t = a[4][4];
        a[4][4] = vec[3][0];
        int i =vec[3][1];
        int j =vec[3][2];

        a[i][j] = t;

        for(int i =0;i<5;i++)
        {
            if(t==vec[i][0])
            {
                vec[i][1] = i;
                vec[i][2] = j;
            }
        }
    }


    if(a[2][2]!=vec[4][0])
    {
        int t = a[2][2];
        a[2][2] = vec[4][0];
        int i =vec[4][1];
        int j =vec[4][2];

        a[i][j] = t;
    }

    for(int i =0;i<5;i++)
    {
        for(int j =0;j<5;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

}

int main()
{
    int a[][5] = {35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11};
    f(a);
    
    // vector< vector<int> > v;
    // int a1[3] = {1,2,3};
    
    // vector<int> a(a1,a1+3);
    // v.push_back(a);

    // for(auto i :v)
    // {
    //    for (auto j : i)
    //    {
    //        cout<<j<<" ";
    //    }
    //    cout<<endl;
    // }

    //cout<<v[0][2]<<endl;
    system("pause");
}