#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef long long LL;
LL GOD;
int require,base;
LL transform(char *num)//返回数值
{
	int i;
	LL sum=0,nowbase=1;
	for(i=strlen(num)-1;i>=0;i--)
	{
		if(isdigit(num[i]))
			sum+=(num[i]-'0')*nowbase;
		else
			sum+=(num[i]-'A'+10)*nowbase;
		nowbase*=base;
	}
	return sum;
}
int notransform(char *num)
{
	int sp=0;
	sscanf(num,"%d",&sp);
	return sp;
}
char* retransform(LL num)
{
	static char ans[100]={0};
	int index=1;
	if(!num)
		ans[index++]='0';
	while(num)
	{
		int temp=(num%base);
		if(temp<10)
			ans[index++]=temp+'0';
		else
			ans[index++]=temp-10+'A';
		num/=base;
	}
	ans[0]=index-1;
	return ans;
}
void runorder(char *str)
{
	char Torder[9][10]={"NUM","ADD","SUB","MUL","DIV","MOD","CHANGE","EQUAL","CLEAR"};
	char sp[10];
	sscanf(str,"%s",sp);
	char spnum[100]={0};
	if(strlen(sp)!=strlen(str))
		sscanf(str,"%*s%s",spnum);
	int i,j;
	char *temp=NULL;
	for(i=0;i<9;i++)
	{
		if(!strcmp(sp,Torder[i]))
		{
			switch(i)
			{
				case 0:
					if(require==0)
						GOD=transform(spnum);
					else
					{
						if(require==1)
							GOD+=transform(spnum);
						if(require==2)
							GOD-=transform(spnum);
						if(require==3)	
							GOD*=transform(spnum);
						if(require==4)	
							GOD/=transform(spnum);
						if(require==5)	
							GOD%=transform(spnum);
						require=0;
					}
					break;
				case 1:
					require=1;break;
				case 2:
					require=2;break;
				case 3:
					require=3;break;
				case 4:
					require=4;break;
				case 5:
					require=5;break;
				case 6:
					base=notransform(spnum);break;
				case 7:	
					temp=retransform(GOD);
					for(j=temp[0];j>=1;j--)
						putchar(temp[j]);
					putchar('\n');
					break;
				case 8:
					GOD=0;
					require=0;
			}
		}
	}
}
int main(int argc,char **argv)
{
	int cnt;
	scanf("%d",&cnt);
	base=10,require=0;
	while(cnt--)
	{
		char order[30];
		scanf("%*c%[^\n]",order);
		runorder(order);
	}
    system("pause");
	return EXIT_SUCCESS;
}