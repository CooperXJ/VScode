#include <stdio.h>
#include <string.h>

int main() {
	puts("�������ַ���(30�ַ�����):");
	char s[100];
	char res[100];
	gets(s);
	
	int i;
	int j =0;
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			continue;
		}
		else
		{
			res[j++] = s[i];
		}
	}
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			res[j++] = s[i];
		}
	}
	puts("���Ϊ��");
	for(i=0;i<strlen(res);i++)
	{
		printf("%c",res[i]);
	}
	
}
