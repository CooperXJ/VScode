#include <iostream>
using namespace std;


int divide(int a,int b)
{
	if(b==0) throw 1;
	return a/b;
}

int main()
{
	int a,b;
	
	try{
		cout<<"请输入a和b的值："<<endl;
		cin>>a>>b;
		cout<<"a/b"<<divide(a,b)<<endl;
	}
	catch(int){
		cout<<"数学是体育老师教的吧？？？？"<<endl;
		cin>>a>>b; 
		cout<<"a/b = "<<divide(a,b)<<endl;
	}
	//finally{
		///cout<<"滴滴，脑残卡"<<endl;
	//}	
	
}
