#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag;
int IsNumIn(char word[])
{
	int i;
	for(i=0;i<strlen(word);i++)
	{
		if(word[i]>='0'&&word[i]<='9')
		{
			printf("error\n");
			return 1;
		}
	}
	return 0;	
}

int IsSpcIn(char word[])
{
	int i;
	for(i=0;i<strlen(word);i++)
	{
		if(word[i]==' ')
		{
			return 1;
		}
	}
	return 0;
}

void Trim(char oldWord[], char newWord[])
{
	int i;
	int j =0;
	for(i=0;i<strlen(oldWord);i++)
	{
		if(oldWord[i]==' '&&oldWord[i-1]!=' '&&oldWord[i+1]!=' ')
		{
			flag = 2;
			return;
		}
	}
	
 	i = 0;
	while(i<strlen(oldWord))
	{
		if(oldWord[i]==' ')
		{
			i++;
			continue;
		}
		else
		{
			newWord[j++] = oldWord[i];
		}
		i++;
	}
	
	for(i=0;i<j;i++)
	{
		printf("%c",newWord[i]);
	}
}

void Seg(char words[], char wArray[][100])
{
	int i,j,k;
	i = 0;
	j = 0;
	k = 0;
	int f = 0;
	if(flag==2)
	{
		while(i<strlen(words))
		{
			while(words[i]==' ')
			{
				i++;
				if(f!=0)
				{
					j++;
					k = 0;
				}
			}
			while(words[i]!=' '&&words[i]!='\r')
			{
				wArray[j][k++] = words[i];
				i++;
				f = 1; 
			}
		}
		
		for(i=0;i<=j;i++)
		{
			puts(wArray[i]);
		}
	}
	else
	{
		return;
	}

} 

int main()
{
	char s[100];
	gets(s);
	
	if(IsNumIn(s))
	{
		return 0;
	}
	else if(IsSpcIn(s))
	{
		char new1[100];
		Trim(s,new1);
		char res[100][100];
		Seg(s,res);
	}
}
