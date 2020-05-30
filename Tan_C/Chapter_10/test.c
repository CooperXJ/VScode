#include <stdio.h>

int main()
{
    //fopen(file_path,operation) 如果operation为r 那么遇到不存在的文件就会返回NULL,如果为w,则遇到不存在的文件会新建文件
    char path[] = "C:/Users/Aaron/Desktop/s3/4.txt";
    FILE *fp;
    if((fp = fopen(path,"r"))==NULL)
        printf("fail\n");
    
    getchar();
}