#include<iostream>
#include<deque>
using namespace std;
int main()
{   
    deque<int>vi;
    vi.push_back(1);
    int n,i,j,carry,result;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(carry=0,j=vi.size()-1;j>=0;j--)
        {
            result=i*vi[j]+carry;
            vi[j]=result%10;
            carry=result/10;
        }
        while(carry)  //carry代表位数
        {
            vi.push_front(carry%10);
            carry/=10;
        }
    }
    for(i=0;i<vi.size();i++)
        cout<<vi[i];
    cout<<endl;

    system("pause");
    return 0;
}