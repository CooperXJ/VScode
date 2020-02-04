#include <iostream>
using namespace std;
int main()
{
	int a[3] = {1,1,0};
	int b[3] = {1,0,1};
	int c[4] = {0};
	
	for(int i =2;i>=0;i--)
	{
		if(a[i]+b[i]==2)
		{
			c[i] = 1;
			c[i+1] = 0;
		}
		else
			c[i+1] = 1;
	}
	
	int A[5] = { 0, 1, 1, 0, 0 };

	int B[5] = { 1, 1, 0, 1, 0 };

	int C[6];

	int carry = 0;

	int i;

	for (i = 4; i >=0; --i)

	{

		C[i+1] = (A[i] + B[i] + carry) % 2;//通过两个数组相差一位    直接在原来的基础上俩carry = C[i] 

		carry = (A[i] + B[i] + carry) / 2;

	}

	C[i+1] = carry;//最后一个 i = -1 
	for(int i =0;i<4;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
}
