#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct{
	char minutes[100];
	char hours[100];
	char day_of_month[100];
	char month[100];
	char day_of_week[100];
	char command[100];
}Cron;

void spilt(char *s,vector<string> &v)
{
	v.clear();
	char *p = strtok(s," ");
	while(p){
		v.push_back(p);
		p = strtok(NULL," ");
	}
}

void CaculateWeekDay(int y, int m, int d)

{

    if(m==1||m==2) //把一月和二月换算成上一年的十三月和是四月

    {

        m+=12;

        y--;

    }

    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return Week; 
} 

int main()
{
	int n,s,t;
	cin>>n>>s>>t;
	
	vector<Cron> vec(n);
	
	for(int i =0;i<n;i++)
	{
		cin>>vec[i].minutes;
		cin>>vec[i].hours;
		cin>>vec[i].day_of_month;
		cin>>vec[i].month;
		cin>>vec[i].day_of_week;
		cin>>vec[i].command;
		
		int len = strlen(vec[i].minutes)
		for(int j =0;j<len;j++)
		{
			if(vec[i].minutes[j]-'0'<10)
			{
				v
			}
		}
	}
	return 0;
} 
