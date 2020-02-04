#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	vector<int>  price;
	vector<int>  nextprice;
	int T;
	cin>>T;
	
	for(int i =0;i<T;i++)
	{
		int p;
		cin>>p;
		price.push_back(p);
	}
	
	vector<int>::iterator it;
	
	for(it = price.begin();it!=price.end()-1;it++)
	{
		if(it==price.begin())
		{
			nextprice.push_back((*it+*(it+1))/2);
		}
		
		
		else
			nextprice.push_back((*(it-1)+*it+*(it+1))/3);
	}
	
	nextprice.push_back((*(price.end()-2)+*(price.end()-1))/2);
	
	for(it = nextprice.begin();it!=nextprice.end();it++)
	cout<<*it<<" ";
	
	cout<<endl;
	
	
	return 0;
}

/*
	对于vector数组的end指针来说时该数组的最后一个的下一个   
*/
