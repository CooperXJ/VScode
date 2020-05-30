#include <stdio.h>

/*
    1.fgetc()  读取文件，按字符读取
    2.fputc() 写入文件，按字符写入
*/
int main()
{
    FILE * fp;
    char path[] = "C:/Users/Aaron/Desktop/s3/1.txt";

    fp = fopen(path,"r");
    char ch = fgetc(fp);
    while (!feof(fp))
    {
        printf("%c",ch);
        ch = fgetc(fp);
    }

    fclose(fp);

    FILE *in = fopen("C:/Users/Aaron/Desktop/s3/1.txt","r");
    FILE *out = fopen("C:/Users/Aaron/Desktop/s3/5.txt","w");

    ch = fgetc(in);
    while (!feof(in))
    {
        fputc(ch,out);
        ch = fgetc(in);
    }
    
    fclose(in);
    fclose(out);
   printf("\n");
   getchar();
}