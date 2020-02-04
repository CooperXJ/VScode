#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int num;
	int Val;
}St;

int check(int val,int exit)
{
	if(val%exit==0)
	{
		return 1;
	}
	
	if((val - (val/10)*10)==exit)
	{
		return 1;
	}
	else
	return 0;
}
int main()
{
	int total,exit;
	cin>>total>>exit;
	int val = 1;
	
	vector<St> vec(total);
	vector<St>::iterator it = vec.begin();
	
	for(int i =0;i<total;i++)
	{
		vec[i].num = i+1;
	}
	
	
	//方法1   超时 
	/*while(vec.size()!=1)
	{
		for(int i = 0;i<vec.size();i++,val++)
		{
			vec[i].Val = val;
		}
	
		for(;it!=vec.end();)
		{
			if(check((*it).Val,exit))
			it = vec.erase(it);
			
			else
			it++;
			
		}
		
		it = vec.begin();

	}*/
	
	//方法2 
	while(vec.size()!=1)
	{
		if(it==vec.end())
		{
			it = vec.begin();
			(*it).Val = val;
			if(check((*it).Val,exit))
			{
				it = vec.erase(it);
				it-=1;
			}
		}
		
		else
		{
			(*it).Val = val;
			if(check((*it).Val,exit))
			{
				it = vec.erase(it);
				it-=1;
			}
		}
		
		it++;
		val++;
		
		/*cout<<"-----"<<endl;
		for(int i =0;i<vec.size();i++)
		{
			cout<<"num:  "<<vec[i].num<<"  val: "<<vec[i].Val<<endl; 
		}*/
	}
	
	cout<<vec[0].num<<endl;
	
}
