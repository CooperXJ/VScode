#include <iostream>
using namespace std;

class Dog
{
	public:
		static int age;
		/*Dog(string name = "Jack"){
			this->name = name;
		}*/
		
		virtual void bite(){
			cout<<"WAWA"<<endl;
		}
	private:
	string name;	
 };
 
 int Dog::age = 10;
 
 class Little_dog:public Dog
 {
 	public:
 		/*Little_dog(string name):Dog(name)
 		{
 			//cout<<"haha"<<endl;
		 }*/
 		void bite(){
 			cout<<"wawa"<<endl;
		 }
 		
  }; 
  
int main()
{
	//Dog d("Jack");
	//cout<<d.age<<endl;
	//d.bite();
	Dog d;
	Dog *D;
	D = &d;
	D->bite();
	cout<<sizeof(D)<<endl;
	Little_dog ld;
	//ld.bite();
	D = &ld;
	D->bite();
	return 0;
 } 
