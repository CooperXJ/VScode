
#include<bits/stdc++.h>

using namespace std;

  int gcd (int x, int y)

     {

	        if (y==0)

	           return x;

	        else 

	            return gcd (y,x%y); 

	 }


int f(int a,int b)

{

	while (b)

	{

	  int t=a%b;

	  a=b;

	  b=t; 	

	}

   return a;

}



int main()

{

	int m = f(192,5);
	cout<<m<<endl;
    system("pause");
	return 0;

}
