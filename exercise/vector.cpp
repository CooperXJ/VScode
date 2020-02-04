/*2018/7/20   14点59分*/ 
/*vector解析*/
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
	//Nums.push_back(5);这里如果再添加一个元素的话在下面的swap中会出现问题 
	for(int i =0;i<nums.size();i++)
	{
		cout<<nums.at(i)<<endl;
	}
	swap(nums,Nums);
	//swap必须时交换两个vector 
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
	reverse(nums.begin(),nums.end()); //倒置 
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;
	
	nums.erase(nums.begin(),nums.end());//删除 
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<"-1"<<endl;
	cout<<endl;
	nums.insert(nums.begin(),9);//插入 
	
	for(it = nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
	}
}
