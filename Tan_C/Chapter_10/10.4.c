#include <stdio.h>

/*
    1.fread(buff,size,count,fp)  buff:存放文件读入数据的存储区的地址，size：读入的字节数，count:读入多少个数据项，每个数据项的大小为size，fp为指针类型
    2.fwrite(buff,size,count,fp) buff:从此地址开始的存储区中的数据向文件输出
    这两者都是利用二进制输入和输出的，和fputs、fgets要区别开来
*/
typedef struct
{
    int num;
    int age;
}stu;

int main()
{
   FILE *fp = fopen("C:/Users/Aaron/Desktop/s3/student.txt","wb");
   stu s;
   s.num = 110;
   s.age = 23;

   fwrite(&s,sizeof(s),1,fp);
   fclose(fp);

   stu s1;
   FILE *in = fopen("C:/Users/Aaron/Desktop/s3/student.txt","rb");
   fread(&s1,sizeof(stu),1,in);
   printf("%d %d\n",s1.num,s1.age);

    fclose(in);
   getchar();
}