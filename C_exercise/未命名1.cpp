#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char ch;
	int val; 
}word_count;

int main() {
	
	word_count *w = (word_count*)malloc(sizeof(word_count)*26);
	int i = 0;
	int j;
	char ch;
	
	for(i=0;i<26;i++)
	{
		w[i].ch = 'A'+i;
		w[i].val = 0;
	}
	

	while((ch=getchar())!='\n')
	{
		//printf("ch = %c\n",ch);
		for(i=0;i<26;i++)
		{
			//printf("w[%d]  = %c\n",i,w[i].ch);
			if(ch==w[i].ch||ch==(w[i].ch+32))
			{
				w[i].val = w[i].val+1;
				break;
			}
		}
		
	}
	
//	for(i= 0;i<26;i++)
//	{
//		printf("%c(%c):%d\n",w[i].ch,w[i].ch+32,w[i].val);
//	}
	
	for(i=25;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(w[i].val>w[j].val)
			{
				word_count t = w[i];
				w[i] = w[j];
				w[j] = t;
			}
		}
	}
	
	for(i=0;i<26;i++)
	{
		for(j=i+1;j<26;j++)
		{
			if(w[i].val==w[j].val&&w[i].ch>w[j].ch)
			{
				word_count t = w[i];
				w[i] = w[j];
				w[j] = t;
			}
		}
	}
	for(i= 0;i<26;i++)
	{
		printf("%c(%c):%d\n",w[i].ch,w[i].ch+32,w[i].val);
	}
}
