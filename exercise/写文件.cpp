#include <fstream>

#include <iostream>

using namespace std;

int main()

{

	int a[10];

	ifstream in("����.txt");

	for(int i=0;i<10;i++)

		in>>a[i];

	for(int i=0;i<10;i++)

		cout<<a[i]<<endl;

	ofstream out("���.txt");

	out<<"��ȫojbk";

	in.close();

	out.close();

	cin.get();

}

