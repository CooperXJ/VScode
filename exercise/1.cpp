#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(map<int,int> Map,int target) {
			vector<int> twoSum;
			Map.insert(pair<int,int>(1,1));
			Map.insert(pair<int,int>(2,2));
			Map.insert(pair<int,int>(3,3));
			Map.insert(pair<int,int>(4,4));
			Map.insert(pair<int,int>(5,5));
			for(int i =6; i<12; i++) {
				Map[i] = i;
			}
			for(int i =0; i<Map.size(); i++) {
				int complement = target - Map[i];
				if(Map.find(complement)!=Map.end())
				{
					//twoSum.push_back(i);
					//twoSum.push_back(Map.find(complement));
					twoSum.push_back(i);
				}
			}
			
			return twoSum;
		}

};
int main() {
	Solution s;
	map<int,int> Map;
	map<int,int>::iterator it;
	vector<int> vec = s.twoSum(Map,3);
	vector<int>::iterator iter;
	Map.insert(pair<int,int>(1,0));
	Map.insert(pair<int,int>(2,2));
	for(int i =0;i<Map.size();i++)
	{
		cout<<Map[i]<<" ";
	}
	cout<<endl;
	for(it = Map.begin();it!=Map.end();it++)
	{
		cout<<it->second<<" ";
	}
	cout<<endl;
	for(iter = vec.begin();iter!=vec.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
}
