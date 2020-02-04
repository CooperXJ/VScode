#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main( int argc, char** argv )
{
	/*
  char str[] = "I am a  stduent,you are teacher!";
  char spliter[] = ",!"; 

  char * pch;
  pch = strtok( str, spliter );
  while( pch != NULL )
  {
    cout << pch << endl;
    pch = strtok( NULL, spliter );
  }*/
  
  /*string s = "1234";
  cout<<s.substr(1)<<endl;*/
  
  /*vector<int> t;
  t.push_back(1);
  t.push_back(2);
  t.push_back(3);
  cout<<t.front()<<endl;
  cout<<t.back()<<endl; 
  
  map<string int> m;*/
  
  vector<int> vec;
  
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	 cout<<*(vec.erase(vec.begin()+1))<<endl;;
	
	
	/*for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
	{
		cout<<*it<<endl;
	}*/
	
	
   
  return 0;
}

