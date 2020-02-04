#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> vec;

	for(int i =0; i<n; i++) {
		vec.push_back(i+1);
	}

	for(int i =0; i<m; i++) {
		int p,q;
		cin>>p>>q;

		if(q>0) {
			//cout<<*(vec.begin()+p+q)<<endl;
			vec.insert(find(vec.begin(),vec.end(),p)+q+1,p);//因为是将数字挤到前面去，所以应该插入到该数字的后面
			/*for(int i =0; i<vec.size(); i++) {
				cout<<vec[i]<<" ";
			}
			cout<<endl;*/
			vec.erase(find(vec.begin(),vec.end(),p));
			/*for(int i =0; i<vec.size(); i++) {
				cout<<vec[i]<<" ";
			}*/
		}

		if(q<0) {
			vector<int>::iterator it = find(vec.begin(),vec.end(),p);
			vec.insert(find(vec.begin(),vec.end(),p)+q,p);
			vec.erase(it+1);
			/*for(int i =0; i<vec.size(); i++) {
				cout<<vec[i]<<" ";
			}*/
		}
	}

	for(int i =0; i<vec.size(); i++) {
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	return 0;
}
