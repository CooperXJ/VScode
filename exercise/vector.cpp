/*2018/7/20   14��59��*/ 
/*vector����*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums;
	vector<int> Nums;
	nums.push_back(1);
	nums.push_back(2);
	Nums.push_back(3);
	Nums.push_back(4);
	//Nums.push_back(5);������������һ��Ԫ�صĻ��������swap�л�������� 
	for(int i =0;i<nums.size();i++)
	{
		cout<<nums.at(i)<<endl;
	}
	swap(nums,Nums);
	//swap����ʱ��������vector 
	for(int i =0;i<nums.size();i++)
	{
		cout<<nums.at(i)<<endl;
	}
	for(int i =0;i<nums.size();i++)
	{
		cout<<Nums.at(i)<<endl;
	}
	cout<<endl;
	vector<int>::iterator it;
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	nums.push_back(5);
	cout<<endl;
	reverse(nums.begin(),nums.end()); //���� 
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;
	
	nums.erase(nums.begin(),nums.end());//ɾ�� 
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<"-1"<<endl;
	cout<<endl;
	nums.insert(nums.begin(),9);//���� 
	
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
}
