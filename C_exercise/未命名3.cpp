#include <stdio.h>
#include <malloc.h>
void print(int a[][4])//int (*a)[4]
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

void input(int a[][4])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);		
	}
}

void show(int *a)
{
	int i;
	for(i=0;i<12;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void input_1(int **a)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);		
	}
}

void show_1(int **a)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j = 0;j<4;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
//	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
//	int *p;
//	p = *a;
//	show(*a);
//	printf("%d\n",*p+1);
//	printf("%d\n",**a+6);
//	
//	//二维数组的访问方式一：
//	// a[i]+j(第i行第j列个元素的地址)指向a[i][j], 有*（a[i]+j）=a[i][j], 
//	//而a[i] = *(a+i) 
//	printf("%d\n",*(a[0]+2));
//	printf("%d\n",*(*a+2));
//	input(a);
//	print(a);

	int **a = (int**)malloc(sizeof(int*)*3);
	int i;
	for(i=0;i<3;i++)
	{
		a[i] = (int*)malloc(sizeof(int)*4);
	}
	input_1(a);
	show_1(a);	
}
