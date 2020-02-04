#include <iostream>
#include <bitset>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stack> 
#include <queue>
using namespace std;

int GCD(int a,int b)
{
	return b==0?a:GCD(b,a%b); 
}

string ntransform(int a,int n)
{
	string s;
	int b = a;
	while(b)
	{
		s+=('0'+b%n);
		b/=n;
	}
	
	string res;
	for(int i = s.length()-1;i>=0;i--)
	{
		res+=s[i];
	}
	//cout<<res<<endl;
	return res;
}

int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;	
	q.pop();
	cout<<q.front()<<endl;
 } 
