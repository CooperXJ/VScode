#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *in,*out;
   char path1[] = "C:/Users/Aaron/Desktop/s3/1.txt";
   char path2[] = "C:/Users/Aaron/Desktop/s3/4.txt";

   if((in=fopen(path1,"r"))==NULL)
   {
       printf("no file1!\n");
       exit(0);
   }
   if((out=fopen(path2,"w"))==NULL)
   {
       printf("can not open file2!\n");
       exit(0);
   }

   char ch = fgetc(in);
   while (!(feof(in)))//feof(in)判断是否遇到末尾，返回值为1则表明文件末尾标志已被读出，返回0则标志文件末尾标志未被读出
   //！feof也可以替换成ch!=EOF或者ch!=-1
   {
       fputc(ch,out);
       ch = fgetc(in);
   }
   
   fclose(in);
   fclose(out);

   getchar();
}