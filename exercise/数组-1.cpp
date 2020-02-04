/*2018-7-25  08点26分*/
/*数组是排好序的*/ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.empty())
    	return 0;
    	
    	int num =0;
    	for(int i =1;i<nums.size();i++)
    	{
    		if(nums[num]!=nums[i])
    		{
    			num++;
    			nums[num] = nums[i]; 
			}
		}
		return num+1;
        
    }
};

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);	
	Solution s;
	cout<<s.removeDuplicates(nums)<<endl;
 } 
