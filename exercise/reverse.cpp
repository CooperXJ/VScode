#include <iostream>
using namespace std;
unsigned int reverse(unsigned int n)
{
	unsigned int result = 0;
	while(n%10!=0)
	{
		result = result*10+n%10;
		n = n/10;
	}
	
	return result;
}

int main()
{
	cout<<reverse(62354879643)<<endl;
 } 
