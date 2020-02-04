/*9.18   00点56分*/ 
#include <iostream>
using namespace std;

void merge(int a[],int p,int q,int r)
{
	int n1 = q - p +1;  //n1为数组1的长度 
	int n2 = r - q;		//n2为数组2的长度
	int L[n1+1] = {0};
	int R[n2+1] = {0};
	for(int x =0;x<n1;x++)
	{
		L[x] = a[p+x];
	 }
	 
	 L[n1] =  1000;
	 
	 for(int y = 0;y<n2;y++)
	 {
	 	R[y] = a[q+y+1];
	 }
	 R[n2] = 1000;
	 
	 int i =  0;
	 int j =  0;
	  
	 for(int k = p;k<8;k++)
	 {
	 	if(L[i]<R[j]||L[i]==R[j])
	 	{
	 		a[k] = L[i];
	 		i++;
		 }
		 else 
		 {
		 	a[k] = R[j];
		 	j++;
		 }
	 }
	 cout<<"R[4] = "<<R[4]<<endl;
	 cout<<"i = "<<i<<"  j = "<<j<<endl;
	 for(int i =0;i<r+1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[8] = {3,4,5,6,1,2,7,8};
	merge(a,0,3,7);
}
