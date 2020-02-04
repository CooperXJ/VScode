#include  <iostream>

using namespace std;

int main()
{
	int score = 0;
	int x = 0;

	for(int i =0;i<30;i++)
	{
		int t;
		cin>>t;
		
		if(t==0)
		break;
		
		else
		{
			//vec.push_back(t);
			if(t==1)
			{
				x = 0;
				score+=1;
			}
			
			else
			{
				x+=1;
				score += x*2;
			}
		}
	}
	cout<<score<<endl;
	return 0;
}
