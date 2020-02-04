#include <stdio.h>
#include <string.h>
#include <math.h>
#define ARR_SIZE  80


int main() {
	char s[5] = {'1','2','3','4','5'};
	char s1[5] = {'10','20','30','40','50'};
	
	char t[5];
	strcpy(t,s);
	strcpy(s,s1);
	strcpy(s1,t);
	int i;
	for(i=i;i<5;i++)
	{
		printf("a[%d]=%2c,",i,s[i]);
	}
	printf("\n");
	for(i=i;i<5;i++)
	{
		printf("b[%d]=%2c,",i,s1[i]);
	}
}
