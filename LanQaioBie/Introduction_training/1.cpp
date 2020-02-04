
#include<cstdio>
#include <iostream>
using namespace std;

int main(){

	int F[1000001];

	F[1]=1;

	F[2]=1;

	int n;

	scanf("%d",&n);

	for(int i=3;i<=n;i++){

		F[i]=(F[i-1]+F[i-2])%10007;

	}

	printf("%d",F[n]);
    system("pause");
	return 0;

}
