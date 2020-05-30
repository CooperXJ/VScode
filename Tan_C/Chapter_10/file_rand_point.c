#include <stdio.h>

/*
    1.rewind(fp) 将文件指针fp重置到文件开头
    2.fseek(fp,size,pos) size：位移大小，size>0 前移 size<0 后移  
    pos :
        0:文件开始位置
        1：文件结束位置
        2：文件末尾位置  
*/
typedef struct 
{
   int num;
   int age;
}stu;

int main()
{
    FILE *out = fopen("C:/Users/Aaron/Desktop/s3/student.txt","wb+");
    stu s[3];
    for(int i =0;i<3;i++)
    {
        s[i].num = i+1;
        s[i].age = 20+i;
    }

    for(int i =0;i<3;i++)
    {
        fwrite(&s[i],sizeof(stu),1,out);
    }

    rewind(out);//将文件指针重置到文件开头

    stu s1[3];
    for(int i =0;i<3;i+=2)
    {
        fseek(out,i*sizeof(stu),0);
        fread(&s1[i],sizeof(stu),1,out);
        printf("%d %d\n",s1[i].num,s1[i].age);
    }

    fclose(out);
   getchar();
}