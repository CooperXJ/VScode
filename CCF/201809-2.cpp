#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	vector< vector<int> >  array1(T);
	for(int i =0;i<T;i++)
	{
		array1[i].resize(2);
	}
	
	vector< vector<int> >  array2(T);
	for(int i =0;i<T;i++)
	{
		array2[i].resize(2);
	}
	
	for(int i =0;i<T;i++)
	{
		for(int j =0;j<2;j++)
		{
			int val;
			cin>>val;
			array1[i][j] = val;	
		}	
	}
	
	for(int i =0;i<T;i++)
	{
		for(int j =0;j<2;j++)
		{
			int val;
			cin>>val;
			array2[i][j] = val;	
		}	
	}
	
	int time = 0;
	for(int i =0;i<T;i++)
	{
		for(int j =0;j<T;j++)
		{
			if(array1[i][0]<=array2[j][0]&&array1[i][1]>=array2[j][0]&&array1[i][1]<=array2[j][1])
			{
				time+= array1[i][1] - array2[j][0];
				//break;
			}
			else if(array1[i][0]<=array2[j][0]&&array1[i][1]>=array2[i][1])
			{
				time+= array2[j][1] - array2[j][0];
				//break;
			}
			else if(array1[i][0]>=array2[j][0]&&array1[i][1]>=array2[j][1]&&array1[i][0]<=array2[j][1])
			{
				time+= array2[j][1] - array1[i][0];
				//break;
			}
			else if(array1[i][0]>=array2[j][0]&&array1[i][1]<=array2[j][1])
			{
				time+= array1[i][1] - array1[i][0];
				//break;
			}
			
		}
	}
	
	cout<<time<<endl;
	return 0;
 } 
