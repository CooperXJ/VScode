#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int end = n-1;
    int cnt = 0;
    int oddNum = 0;

    for(int i =0;i<end;i++)
    {
        for(int j =end;j>=i;j--)
        {
            if(i==j)
                {
                    if(n%2==0||oddNum==1)
                    {
                        cout<<"Impossible";
                        return 0;
                    }
                    oddNum = 1;
                    cnt+=n/2-i;
                }
                else if(s[i]==s[j])
                {
                    for(int k = j;k<end;k++)
                    {
                        swap(s[k],s[k+1]);
                        cnt++;
                    }
                    end--;
                    break;
                }
        }
    }
    cout<<cnt;
    
    return 0;
    system("pause");
}