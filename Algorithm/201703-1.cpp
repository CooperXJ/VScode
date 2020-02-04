#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	int people = 0;
	
	vector<int> vec; 
	for(int i =0;i<n;i++)
	{
		int a;
		cin>>a;
		vec.push_back(a);
	}
	
	vec.push_back(0);
	/*for(int i =0;i<n;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;*/
	
	int weight = 0;
	for(int j =0;j<=n;j++)
	{
		if(weight<k)
		{
			weight+=vec[j];
			//cout<<"weight: "<<weight<<endl;
		}
		else 
		{
			//cout<<"1"<<endl;
			weight = 0;
			people++;
			j--;
		}
		
		if(j==n-1&&weight<k&&weight!=0)
		{
			people++;
		}
	}
	
	cout<<people<<endl;
	return 0;
 } 
