#include <iostream>
#include <vector>
using namespace std;

struct a{
	string name;
	int age;
	a(string a,int b):name(a),age(b){
	}
};
int main()
{
	vector<a> vec;
	vec.push_back(a("lucy",20));
	for(int i =0;i<1;i++)
	{
		cout<<vec[i].name<<" "<<vec[i].age<<endl;
	}
	return 0;
}
