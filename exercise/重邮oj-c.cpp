#include <stdio.h>

unsigned int mask[7]={
        1000000,  
        100000,
        10000,
        1000,
        100,
        10,
        1};

void getDigit(unsigned int a,int digits[],int *sum)
{
    for(int i=0;i<7;i++){
        digits[i]=0;
        while(a>=mask[i]){
            digits[i]++;
            printf("%d\n",digits[i]);
            a-=mask[i];
        }
        if(digits[i]==7)
            {
            	(*sum)++;
            	break;
			}
    }
    
}

int main()
{
	int T;
	T = 1;
	scanf("%d",&T);
	
	for(int i =0;i<T;i++)
	{
		int a = 7,b = 200,sum = 0;
		int digits[7] = {0}; 
		scanf("%d %d",&a,&b);
		
		a+=1;
		
		while(a%7!=0)
		{
			a++;
		}
		
		
		
		for(int i =a;i<b;)
		{
			
			getDigit(i,digits,&sum);
			for(int i =0;i<7;i++)
			{
				printf("%d  ",digits[i]);
			}
			printf("\n");
	
				i+=7;
		}
		
		printf("%d\n",sum);	
	}
}
