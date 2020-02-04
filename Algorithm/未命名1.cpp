#include <stdio.h>
#include <string.h>
#include <math.h>
#define ARR_SIZE  80


int main() {
	int i,j,k;
	printf("Man\tWomen\tChildren\n");
	for(i=0;i<20;i++)
	{
		for(j=0;j<=25;j++)
		{
			for(k=0;k<=50;k++)
			{
				if(i*3+j*2+k*1==50&&i+j+k==30)
				{
					printf("%3d\t%5d\t%8d\n",i,j,k);
				}
			}
		}
	}
}
