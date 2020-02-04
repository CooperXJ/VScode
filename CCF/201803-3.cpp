#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

void spilt(char *s,vector<string> &v)
{
	v.clear();
	char *p = strtok(s,"/");
	while(p){
		v.push_back(p);
		p = strtok(NULL,"/");
	}
}

int isNum(string str)
{
	stringstream sin(str);
	double d;
	char c;
	
	if(!(sin>>d))
	{
		return 2;
	}
	if(sin>>c)
	{
		return 2;
	}
	return 1;
}

int pipei(string str1,string str2)
{
	if(str1.find("int")!=string::npos&&isNum(str2))
	{
		return 1;
	}
	if(str1.find("string")!=string::npos)
	{
		return 2;
	}
}

int main()
{
	int m,n;
	cin>>m>>n;
	
	
	vector< vector<string> > vec;
	for(int i =0;i<=m;i++)
	{
		vector<string> v;	
		char ch[100];
		gets(ch);
		
		spilt(ch,v);
		
		vec.push_back(v);
	}
	
	/*cout<<vec.size()<<endl;*/
	vector< vector<int> > Vec;
	for(int i =0;i<vec.size();i++)
	{
		vector<int>  vect;
		for(int j =1;j<vec[i].size();j++)
		{
			if(vec[i][j].find("int")!=string::npos)
			{
				//cout<<vec[i][j]<<" "<<"Yes"<<endl;
				vect.push_back(1);
			}
			else if(vec[i][j].find("string")!=string::npos)
			{
				//cout<<vec[i][j]<<" "<<"No"<<endl;
				vect.push_back(2);
			}
			else
			{
				//cout<<vec[i][j]<<" "<<"No"<<endl;
				vect.push_back(3);
			}
		}
		//vect.pop_back();
		Vec.push_back(vect);
		vect.clear();
	}
	
	/*for(int i =0;i<Vec.size();i++)
	{
		//cout<<Vec[i].size()<<endl;
		for(int j =0;j<Vec[i].size();j++)
		{
			cout<<Vec[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	vector< vector<string> > ve;
	for(int i =0;i<n;i++)
	{
		vector<string> v;	
		char ch[100];
		gets(ch);
		
		spilt(ch,v);
		
		ve.push_back(v);
	}
	
	vector< vector<int> > VEc;
	for(int i =0;i<ve.size();i++)
	{
		vector<int>  vect;
		for(int j =1;j<ve[i].size();j++)
		{
			vect.push_back(isNum(ve[i][j]));
		}
		vect.push_back(3);
		VEc.push_back(vect);
		vect.clear();
	}
	
		
	/*for(int i =0;i<VEc.size();i++)
	{
		//cout<<VEc[i].size()<<endl;
		for(int j =0;j<VEc[i].size();j++)
		{
			cout<<VEc[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	for(int i =0;i<VEc.size();i++)
	{
		for(int j =0;j<Vec.size();j++)
		{
			if(VEc[i]==Vec[j])
			{
				vec[j][vec[j].size()-1].erase(vec[j][vec[j].size()-1].begin());
				cout<<*(vec[j].end()-1)<<" ";
				for(int k =1;k<VEc[i].size();k++)
				{
					cout<<ve[i][k]<<" ";
				}
				cout<<endl;
			}
		}
	}
	
	return 0;
}




