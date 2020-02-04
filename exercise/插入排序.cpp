#include <iostream>
//2018年8月27日21:07:05  要注意比较的数是后面的数  是将前面已经排好序的数与后面未排序的数进行比较   
using namespace std;
void sort(int a[]) {
	for(int i =1; i<6; i++) {
		int key = a[i];
		int j = i-1;
		while(i>=0&&a[j]>key) {
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
	}
}
int main() {
	int a[6] = {2,5,3,4,7,1};
	sort(a);
	for(int i =0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

