#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int day;
    cin>>day;

    vector<int> vec;
    vector<int> res;
    for(int i =0;i<day;i++)
    {
        int k;
        cin>>k;
        vec.push_back(k);
    }

    for(int i =0;i<day-1;i++)
    {
        
            int r = abs(vec[i]-vec[i+1]);
            res.push_back(r);
        
    }

    vector<int>::iterator min = max_element(res.begin(),res.end());
    cout<<*(min)<<endl;
    system("pause");
}