#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int r)
{
	int n1 = m - l +1;
	int n2 = r - m;
	
	int L[n1+1] = {0};
	int R[n2+1] = {0};
	
	L[n1] = 100;
	R[n2] = 100;
	for(int i =0;i<n1;i++)
	{
		L[i] = a[i];
	}
	
	for(int i =n1;i<r+1;i++)
	{
		R[i-n1] = a[i];
	}

	int i =0;
	int j =0;
	for(int k = l;k<r+1;k++)
	{
		if(L[i]>R[j])
		{
			a[k] = R[j];
			j++;
		}
		else
		{
			a[k] = L[i];
			i++;
		}
	}
	cout<<"i = "<<i<<endl;
	cout<<"j = "<<j<<endl;
}

int main()
{
	int a[8] = {3,4,5,6,1,2,7,8};
	merge(a,0,3,7);
	for(int i =0;i<8;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
 } 
