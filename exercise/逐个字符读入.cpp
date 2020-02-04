#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char c, fileName[60];
	int count = 0;//字符个数
	cout << "Please enter the file's name:\n";
	cin.getline(fileName,60);
	fstream inFile;
	inFile.open(fileName);
	if (!inFile.is_open()) {
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
	}
	inFile >> c;
	while (!inFile.eof()) {
		if (inFile.good()) {
			count++;
			inFile >> c;
		}
	}
	cout<<"count: "<<count<<endl;
	int s = 0;
	fstream   fout;
	fout.open("D:\\learning\\code\\C++\\test.txt",ios::in|ios::out|ios::ate);
	fout.seekp(1);
	fout<<endl; 
	//ifresult.seekp(1,ios::beg);
	//ifresult<<"\r\n"<<endl;
	//while(s!=4)
	{
		//ofresult.seekp(1,ios::beg);
		//ofresult<<"\r\n"<<endl;
		//s++;
	}
	fout.close();
	inFile.close();
	//ofresult<<"123"<<"你是好孩子"<<endl;
	//cout<<"第二次写文件"<<endl;
	//ofresult<<"第二次写文件"<<endl;
}
