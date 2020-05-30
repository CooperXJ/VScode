#include <iostream>
#include <vector> 
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

typedef struct{
	int rank;
	string emu;
	string id;
}T;

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
	int len1,len2;
	cin>>len1>>len2;
	
	string title;
	cin>>title;
	
	vector<T> Vec(len1);
	
	for(int i =0;i<len1;i++)
	{
		vector<string> veC;
		char d[100];
		fgets(d,100,stdin);
		spilt(d,veC);
		
		for(int j = 0;j<veC.size();j++)
		{
			if(j==0)
			{
				int k,dot,l = 0;
				string emu;
				while(veC[0][k])
				{
					if(veC[0][k]=='.')
					{
						dot++;
					}
					else
					{
						emu[l] = veC[0][k];
						cout<<"veC[0][k]: "<<emu<<endl;
						l++;
					}
					
					k++;
				}
				Vec[i].rank = dot/2;
				Vec[i].emu = emu;
			}
			
			else
			{
				Vec[i].id = veC[j];
			}			
		}
	}
	
	system("pause");
	for(int i =0;i<Vec.size();i++)
	{
		cout<<"rank: "<<Vec[i].rank<<"  emu "<<Vec[i].emu<<"  id: "<<Vec[i].id<<endl;
	}
	
	/*for(int i =0;i<len2;i++)
	{
		vector<string> vec;
		int rank;
		char d[100];
		gets(d);
		spilt(d,vec);
		
		vector<string>::iterator it = vec.begin();
		
		if(vec.size()==1)
		{
			vector<int> v;
			int count = 0;
			for(int j =0;j<Vec.size();j++)
			{
				if(vec[0]==Vec[j].emu||vec[0]==Vec[j].id)
				{
					count++;
					v.push_back(j);
				}
			}
			
			cout<<cout<<" ";
			for(int k =0;k<v.size();k++)
			{
				cout<<v[k]<<" ";
			}
			cout<<endl;
		}
		
		else
		{
			for(int i = 0;i<vec.size();i++)
			{
				
			}
		}
	
	}*/	
}