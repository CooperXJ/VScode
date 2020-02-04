#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

/*如果直接使用字符串数组的元素的话  需要提前初始化字符串  例如
string s;
s[0] = 1;
这样的表达就是无效的
因为本身该字符串就是空*/
string transform(int i,int l)
{
    string res;
    int k = 0;
    int number =i;
    while(number){
        res += (number%l+'0');
        number /=l;
    }
    
    string out = res;
    for(int i =0;i<res.length();i++)
    {
        out[i] = res[res.length()-1-i];
    }

    return out;
}

int main()
{
    int L,k;
    cin>>k>>L;
    
    int count = 0;
    int flag = 0;
    for(int i =pow(10,L-1);i<pow(10,L);i++)
    {
        string res = transform(i,k);
        
        for(int j =0;j<res.length()-1;j++)
        {
            if(abs(res[j]-res[j+1])==1)
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            cout<<i<<"     "<<res<<endl;
            count++;
        }
    }

    //cout<<count<<endl;
    system("pause");
}