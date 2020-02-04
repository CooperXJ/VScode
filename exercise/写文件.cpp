#include <fstream>

#include <iostream>

using namespace std;

int main()

{

	int a[10];

	ifstream in("读入.txt");

	for(int i=0;i<10;i++)

		in>>a[i];

	for(int i=0;i<10;i++)

		cout<<a[i]<<endl;

	ofstream out("输出.txt");

	out<<"完全ojbk";

	in.close();

	out.close();

	cin.get();

}

