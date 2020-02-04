#include <iostream>  
#include <fstream>  
#include <string>   
  
using namespace std;  
  
int main()  
{  
    const char * original = "012345678901234567890123456789"; //30 chars  
    const char * overwrite = "abcdeabcde";  
    const char * filename = "test.txt";  
    const char * s = "QQ";
    fstream fout;  
  
    fout.open("test.txt", ios::out|ios::trunc); //destroy any current content  
  
    fout << original;  
  
    fout.close();  
  

    fout.open("test.txt", ios::in|ios::out|ios::ate);  
  
    fout.seekp(7);  
  
    fout << overwrite;
	//fout.seekp(1);
	//fout<< s;
	//fout.seekp(2);
	//fout<<" ";  
    fout.close();  
}
