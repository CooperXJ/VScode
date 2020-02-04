#include<stdio.h>
#include<memory.h>
const int N=1000001;
int a[N],f[257];
int main() {
	int i,x,n,sum,l;
	while(~scanf("%d",&n)) {
		memset(f,0,sizeof(f));
		for(i=0; i<n; i++) scanf("%d",&x),++f[x];
		for(sum=i=0; i<=257&&(sum<<1<=n); i++) {
			sum+=f[i];
			if((sum<<1)==n+1) x=i<<1;
			else if(sum<<1>n) {
				if(i>=0&&sum-f[i]<<1==n) x=i+i-1;
				else x=i<<1;
			}
		}
		if(x&1) printf("%.1lf\n",0.5*x);
		else printf("%d\n",x>>1);
	}
	return 0;
}

