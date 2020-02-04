#include <iostream>
using namespace std;

enum sex
{
	male = 0,
	female,
};

void swap(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

class Dog
{
	public:
	//char *name = new char[10];
	friend class Cat;
	~Dog(){
		//delete []name;
		//name = NULL;
	};
	
	private:
		 int age = 10;
		
};


class Cat
{
	public:
		int age = 12;
		
	void show(Dog &d){
		cout<<d.age<<endl;
	}
	
};

int main()
{
	sex s;
	s = male;
	int a = 1;
	int b = 2;
	//int a1 = &a;
	//int b1 = &b;
	swap(a,b);
	Dog d;
	Cat c;
	c.show(d);
	//cout<<d.age<<endl;
	//cout<<"a = "<<a<<"   b = "<<b<<endl;
	//cout<<s<<endl;
 } 
