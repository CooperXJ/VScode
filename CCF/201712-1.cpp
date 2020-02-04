#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int t;
	int Min = 0;
	cin>>t;
	vector<int> vec(t);
	for(int i =0;i<t;i++)
	{
		int val;
		cin>>val;
		
		vec[i] = val;
	}
	
	Min = abs(vec[0] - vec[1]);
	for(int i =0;i<t;i++)
	{
		for(int j =i+1;j<t;j++)
		{
			int min = abs(vec[i] - vec[j]);
	
			if(min<=Min)
			{
				Min = min;
			}
		}
	}
	
	cout<<Min<<endl;
	
	return 0; 
}
