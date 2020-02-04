#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	int rank;
	string emu;
	string id;
} T;

void spilt(char *s,vector<string> &v) {
	v.clear();
	char *p = strtok(s," ");
	while(p) {
		v.push_back(p);
		p = strtok(NULL," ");
	}
}

int main() {
	int len1,len2;
	cin>>len1>>len2;

	string title;
	cin>>title;

	char a[1];
	gets(a);//吸收掉回车

	vector<T> Vec(len1-1);

	for(int i =0; i<len1-1; i++) {
		vector<string> veC;
		char d[100];
		gets(d);
		spilt(d,veC);

		//cout<<"Vecd 的长度："<<veC.size()<<endl;

		for(int j = 0; j<veC.size(); j++) {
			int k=0,dot=0,l = 0;
			if(j==0) {
				string s;
				while(veC[0][k]) {
					if(veC[0][k]=='.') {
						dot++;
						//cout<<"dot: "<<dot<<endl;
					} else {
						//cout<<"rank: "<<dot<<endl;
						s.append(1,veC[0][k]);
						//cout<<"veC[0][k]: "<<s<<endl;
						l++;
					}

					k++;
				}
				Vec[i].rank = dot/2;
				Vec[i].emu = s;
			}

			else {
				Vec[i].id = veC[j];
			}
		}
	}

	/*for(int i =0;i<Vec.size();i++)
	{
		cout<<"rank: "<<Vec[i].rank<<"  emu "<<Vec[i].emu<<"  id: "<<Vec[i].id<<endl;
	}*/

	for(int i =0; i<len2; i++) {
		vector<string> vec;
		int rank;
		char d[100];
		gets(d);
		spilt(d,vec);
		
		/*for(int i =0;i<vec.size();i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<endl;*/
		
		vector<string>::iterator it = vec.begin();

		vector<int> v;
		int count = 0;

		if(vec.size()==1) {
			for(int j =0; j<Vec.size(); j++) {
				if(vec[0]==Vec[j].emu||vec[0]==Vec[j].id) {
					count++;
					v.push_back(j+2);
				}
			}

			cout<<count<<" ";
			for(int k =0; k<v.size(); k++) {
				cout<<v[k]<<" ";
			}
			cout<<endl;
		}

		/*else if(vec.size()==2) {

			for(int k =0; k<Vec.size(); k++) {
				if(vec[0]==Vec[k].emu&&vec[1]==Vec[k].emu) {
					cout<<"vec[0]:  "<<vec[0]<<" emu"<<Vec[k].emu<<endl;
					count++;
					v.push_back(k+2);
				}
			}
			
			cout<<count<<" ";
			for(int k =0; k<v.size(); k++) {
				cout<<v[k]<<" ";
			}
			cout<<endl;
		}*/

			else if(vec.size()==2) {

			for(int k =0; k<Vec.size(); k++) {
				if(vec[0]==Vec[k].emu&&vec[1]==Vec[k].id) {
					cout<<"vec[0]:  "<<vec[0]<<" emu"<<Vec[k].emu<<" vec[1]"<<vec[1]<<" id"<<Vec[k].id<<endl;
					count++;
					v.push_back(k+2);
				}
			}
			
			cout<<count<<" ";
			for(int k =0; k<v.size(); k++) {
				cout<<v[k]<<" ";
			}
			cout<<endl;
		}
		
	}
}
