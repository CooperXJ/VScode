#include <iostream>
using namespace std;

int paration(int a[],int low,int high)
{
	int pivot = a[low];
	int i = low;
	int j = high;
	
	while(i<j)
	{
		while(i<j&&a[j]>=pivot)j--;
		a[i] = a[j];
		while(i<j&&a[i]<=pivot)i++;
		a[j] = a[i];
	}
	
	pivot = a[i];
	return i;
}

int findkey(int a[],int start,int end,int k)
{
	if(start<end)
	{
		int loc = paration(a,start,end);
		if(loc==k-1)
			return a[loc];
			
		if(k-1<loc)return findkey(a,start,loc-1,k);
		else return findkey(a,loc+1,end,k);
	}
	return a[start];	
}

int main()
{
	int i,k;
	int n;
	int a[] = {19,12,7,30,11,11,7,53,78,25,7};
	
	n = sizeof(a)/sizeof(int);
	
	for(k = 1;k<n+1;k++)
	{
		for(i = 0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		cout<<findkey(a,0,n-1,k);
	}
	return 0;
}
