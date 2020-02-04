#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	
	for(int i =0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	cout<<*(vec.begin()+1)<<endl;
	
	vec.insert(vec.begin()+1,*(vec.begin()+2));
	vec.erase(vec.begin()+1+2);
	for(int i =0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	cout<<*find(vec.begin(),vec.end(),3)<<endl;
	
}
