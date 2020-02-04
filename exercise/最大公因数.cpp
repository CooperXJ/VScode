#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if(a ==0)
	return 0;
	if(b==0)
	return a;
	
	return gcd(b,a%b);
}

int main() {
	int T;
	cin>>T;

	for(int i =0; i<T; i++) {
		int N;
		int sum = 0;
		cin>>N;
		vector<int>  vec(10000,0);
		for(int j =0; j<N; j++) 
		{
			int a;
			cin>>a;
			*(vec.begin()+j) = a; 
		}
		
		for(int i =0;i<N;i++)
		{
			for(int j = i+1;j<N;j++)
			{
				int a = *(vec.begin()+i);
				int b = *(vec.begin()+j);
				if(b==0)
					break;
				int Gcd = gcd(a,b);
				sum+=Gcd;
			}
		}
		
		cout<<sum<<endl;
	}
}
