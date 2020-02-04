
#include <iostream>

#include <cstring>

#include <string>

#include <queue>

#include <stack>

#include <vector>

#include <cmath>

#define inf 0x3f3f3f3f

using namespace std;

long long dl[505][505],xl[505][505];

long long dis1[505],dis2[505];

bool jl[505],vis[505];

int n,m;

void floyd()//预处理小路

{

	for(int k=1;k<=n;k++)

	for(int i=1;i<=n;i++)

	for(int j=1;j<=n;j++)

	{

		if(xl[i][j]>xl[i][k]+xl[k][j]&&xl[i][k]!=inf&&xl[k][j]!=inf)

		{

			xl[i][j]=xl[i][k]+xl[k][j];

		}

	}

}

int main()

{

	memset(xl,inf,sizeof(xl));

	memset(dl,inf,sizeof(dl));

	cin>>n>>m;

	for(int i=1;i<=m;i++)

	{

		int a,b,c,d;

		cin>>a>>b>>c>>d;

		if(a==1&&xl[b][c]>d){

			xl[b][c]=xl[c][b]=d;

		}

		else if(a==0&&dl[b][c]>d){

			dl[b][c]=dl[c][b]=d;

		}

	}

	floyd();

	memset(dis1,inf,sizeof(dis1));

	memset(dis2,inf,sizeof(dis2));

	queue<int>q;

	dis1[1]=dis2[1]=0;

	q.push(1);

	vis[1]=1;

	while(!q.empty())

	{

		int now=q.front();

		q.pop();

		vis[now]=0;

		for(int i=1;i<=n;i++)

		{

			long long v=dl[now][i];

			if(dis1[i]>dis1[now]+v)//大路加大路

			{

				dis1[i]=dis1[now]+v;

				if(vis[i])continue;

				vis[i]=1;

				q.push(i);

			}

			if(dis1[i]>dis2[now]+v)//大路加小路

			{

				dis1[i]=dis2[now]+v;

				if(vis[i])continue;

				vis[i]=1;

				q.push(i);

			}

			if(xl[now][i]<1e10)

			{

				v=xl[now][i]*xl[now][i];

				if(dis2[i]>dis1[now]+v)//小路加大路

				{

					dis2[i]=dis1[now]+v;

					if(vis[i])continue;

					vis[i]=1;

					q.push(i);

				}

			}

		}

	}

	cout<<min(dis1[n],dis2[n])<<endl;

	return 0;

}

