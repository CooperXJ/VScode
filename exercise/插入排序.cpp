#include <iostream>
//2018��8��27��21:07:05  Ҫע��Ƚϵ����Ǻ������  �ǽ�ǰ���Ѿ��ź�����������δ����������бȽ�   
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

