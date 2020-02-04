#include <iostream>
#include <vector>
using namespace std;

typedef struct{
	int type;
	int start;
	int end;
	int len;
}road_info;

int main()
{
	int road_num,road_len;
	cin>>road_num>>road_len;
	
	int consume = 0;
	
	vector<road_info>  vec(road_num);
	
	
	for(int i =0;i<road_len;i++)
	{
		int type,start,end,len;
		cin>>type>>start>>end>>len;
		
		vec[i].type = type;
		vec[i].start = start;
		vec[i].end = end;
		vec[i].len = len;
	}
	
	int j =0;
	
	while(vec[j].end != road_num)
	{
		
	}
	
	return 0;
} 
