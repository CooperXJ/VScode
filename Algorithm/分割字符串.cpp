#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

void spilt(char *s,vector<string> &v)
{
	v.clear();
	char *p = strtok(s," ");
	while(p){
		v.push_back(p);
		p = strtok(NULL," ");
	}
}

int main()
{
	vector<string> vec;
	//char d[100];
	//gets(d);
	
	char d[] = "12 2 3";
	
	spilt(d,vec);
	
	for(int i =0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	string name = "nike";
	string name1 = "N";
	name[0] = name1[0];
	cout<<name<<endl; 
	cout<<endl;
}
