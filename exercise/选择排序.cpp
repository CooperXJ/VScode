#include <iostream>
//2018��8��27��20:24:32   ѡ������ 
//˼·:  ѡ�����С��һ�������˵�ǰ�� 
using namespace std;
void sort(int a[],int len)
{
	for(int i =0;i<len;i++)                       
	{                                              
		for(int j =i+1;j<len;j++)
		{
			if(a[i]>a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void sort_1(int a[],int len)
{
	for(int i =1;i<len;i++)
	{
		int key = a[i];
		int j = i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	 } 
 } 
int main()
{
	int a[6] = {4,3,2,1,5,6};
	sort_1(a,6);
	for(int i =0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
 } 
