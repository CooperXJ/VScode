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
		cout<<"������a��b��ֵ��"<<endl;
		cin>>a>>b;
		cout<<"a/b"<<divide(a,b)<<endl;
	}
	catch(int){
		cout<<"��ѧ��������ʦ�̵İɣ�������"<<endl;
		cin>>a>>b; 
		cout<<"a/b = "<<divide(a,b)<<endl;
	}
	//finally{
		///cout<<"�εΣ��Բп�"<<endl;
	//}	
	
}
