#include <iostream>
using namespace std;

void insertSort(int data[],int n)
{
	int i,j,tmp;
	
	for(i = 1;i<=n-1;i++)
	{
		if(data[i]<data[i-1])
		{
			tmp = data[i];
			data[i] = data[i-1];
			
			for(j = i-2;j>=0&&data[j]>tmp;j--)
				data[j+1] = data[j];
				data[j+1] = tmp;
		}

		for(int r =0;r<n;r++)
		{
			cout<<data[r]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int *bp,*ep;   
	int n,arr[] = {17,392,68,36,776,291,123,255};
	n = sizeof(arr)/sizeof(int);
	insertSort(arr,n);
	
	bp = arr;
	ep = arr+n;
	for(;bp<ep;cout<<*(bp++)<<" ");
	cout<<endl;
	return 0;
 } 
