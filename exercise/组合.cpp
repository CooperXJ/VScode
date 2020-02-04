#include <cstdio>
const int maxn=1000000;
#include <vector>
#include <iostream>
using namespace std;
bool arr[maxn+1]={false};
vector<int> produce_prim_number()
{
        vector<int> prim;
        prim.push_back(2);
        int i,j;
        for(i=3;i*i<=maxn;i+=2)
        {
                if(!arr[i])
                {
                        prim.push_back(i);
                        for(j=i*i;j<=maxn;j+=i)
                                arr[j]=true;
                }
        }
        while(i<maxn)
        {
                if(!arr[i])
                        prim.push_back(i);
                i+=2;
        }
        return prim;
}
//计算n!中素数因子p的指数
int cal(int x,int p)
{
        int ans=0;
        long long rec=p;
        while(x>=rec)
        {
                ans+=x/rec;
                rec*=p;
        }
        return ans;
}
//计算n的k次方对m取模，二分法
int pow(long long n,int k,int M)
{
        long long ans=1;
        while(k)
        {
                if(k&1)
                {
                        ans=(ans*n)%M;
                }
                n=(n*n)%M;
                k>>=1;
        }
        return ans;
}