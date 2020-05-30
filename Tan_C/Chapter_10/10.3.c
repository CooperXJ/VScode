#include <stdio.h>

/*
    1.fgets(str,n,fp) 将读取到的字符串存放到str中，如果遇到"\n"或者是EOF则读入结束，成功返回地址，失败返回NULL
    2.fputs(str,fp)将字符串写入到fp中，成功返回0，否则返回非0值
*/
int main()
{
    FILE *in = fopen("C:/Users/Aaron/Desktop/s3/1.txt","rb");
    FILE *out = fopen("C:/Users/Aaron/Desktop/s3/2.txt","w");

    char str[5][100];
    int i = 0;
    while (fgets(str[i],100,in)!=NULL)
    {   
        printf("%s",str[i]);
        i++;
    }

    for(int i = 0;i<5;i++)
    {
        fputs(str[i],out);
    }

    fclose(in);
    fclose(out);
    getchar();
}