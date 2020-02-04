#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[1000] = {-1};
    for(int i =0;i<n;i++)
    {
        int j;
        cin>>j;
        a[i] = j;
    }

    int check;
    cin>>check;

    int flag = 0;
    for(int k = 0;k<n;k++)
    {
        if(a[k]==check)
        {
            flag = 1;
            cout<<k+1<<endl;
            break;
        }
    }

    if(!flag)
    {
        cout<<-1<<endl;
    }

    system("pause");
}