#include <stdio.h>
void input(int **p,int m,int n)
{
	puts("Please input your data:");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j =0;j<n;j++)
		{
			
			scanf("%d",&p[i][j]);
			
		}
	}
}


int main()
{
	int a[3][4] = {0};
	input(a,3,4);
	

	int max = a[0][0];
	//printf("%d\n",max);
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(max<a[i][j])
			{
				max = a[i][j];
			}
		} 
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(max==a[i][j])
			{
				printf("The maximum is %d, which is in row %d, colum %d\n",max,i,j);
				return 0;
			}
		} 
	}
}
