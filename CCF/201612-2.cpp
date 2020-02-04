#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	if(T<=3500)
	{
		cout<<T;
	}
	
	else if(T<=4955)
	{
		//cout<<"1"<<endl;
		int salary = (T-3500)/0.97+3500;
		cout<<salary;
	}
	
	else if(T<=7655)
	{
		//cout<<"2"<<endl;
		int salary = (T-5000+45)/0.9+5000;
		cout<<salary;
	}
	else if(T<=11455)
	{
		//cout<<"3"<<endl;
		int salary = (T-8000+45+300)/0.8+8000;
		cout<<salary;
	}
	else if(T<=30755)
	{
		//cout<<"4"<<endl;
		int salary = (T-12500+45+300+900)/0.75+12500;
		cout<<salary;
	}
	else if(T<=44755)
	{
		//cout<<"5"<<endl;
		int salary = (T-38500+45+300+900+6500)/0.7+38500;
		cout<<salary;
	}
	else if(T<=62255)
	{
		//cout<<"6"<<endl;
		int salary = (T-58500+45+300+900+6500+6000)/0.65+58500;
		cout<<salary;
	}
	else
	{
		//cout<<"7"<<endl;
		int salary = (T-62255)/0.55+111500;
	}
	return 0;
}
