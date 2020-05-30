#include <stdio.h>

/*
    1.w是从文件开头开始重新写，a是从末尾开始追加
*/
int main()
{
    FILE *fp;
    char ch,fileName[] = "./1.txt";
    if((fp=fopen(fileName,"a+"))!=NULL)
    {
        ch = getchar();
        while (ch!='#')
        {
            fputc(ch,fp);
            ch = getchar();
        }
        
    }

    fclose(fp);
    getchar();
}