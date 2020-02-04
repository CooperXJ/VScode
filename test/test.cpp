#include <iostream>
#include <math.h>
#include <string.h>
#include <malloc.h>
using namespace std;


int di_gui(int i)
{
    if(i==0||i==1)
    {
        return 1;
    }
    else
    {
        return i*di_gui(i-1);
    }
    
}

void show(int arr[4][3])
{
    for(int i =0;i<2;i++)
    {
        for(int j =0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

static int sum(int a,int b)
{
    return  a+b;
}

int sub(int a,int b);

int max(int a,int b)
{
    if(a>b)
        return a;
    else
    {
        return b;
    }
    
}
int main()
{
    // int a[] = {1,2,3};
    // char test[] = {'1','2','\0','3'};
    // cout<<sizeof(int)<<endl;
    // cout<<sizeof(char)<<endl;
    // cout<<sizeof(test)<<endl;
    // puts(test);
    // printf("%s",test);

    // char a[6] = {};
    // scanf("%s",a);
    // puts(a);

    // char str[] = {};
    // char str1[] = {};
    
    //   gets(str);
    // printf("%o\n",str);
    //   gets(str1);
    //   printf("%o\n",str1);
    // // scanf("%s",str);
    // // scanf("%s",str1);
   
    

    // //puts(str);
    // //puts(str1);
    // puts(strcat(str,str1));

    // char str0[10] = {'0'};
    // char str1[10] = "China";
    // strncpy(str0,str1,2);
    // puts(str0);

    // int n =3;
    // int **arr_flag = (int**)malloc(sizeof(int*)*n);
    // for(int i =0;i<n;i++)
    // {
    //     arr_flag[i] = (int*)malloc(sizeof(int)*n);
    // }

    // for(int i =0;i<n;i++)
    // {
    //      for(int j =0;j<n;j++)
    //      {
    //          arr_flag[i][j] = 1;
    //      }
    //      cout<<endl;
    // }

    // for(int i =0;i<n;i++)
    // {
    //      for(int j =0;j<n;j++)
    //      {
    //          cout<<arr_flag[i][j]<<" ";
    //      }
    //      cout<<endl;
    // }

    // cout<<di_gui(3)<<endl;

    // int arr[][3] = {{1,2,3},{4,5,6}};
    // show(arr);
    // cout<<sum(1,2)<<endl;
    // cout<<sub(1,2)<<endl;

    // char a[] = "123";
    // string aa = "123";
    // cout<<aa[2]<<endl;

    /*
    字符串使用指针复制
    char a[] = "I am a student";
    char b[] = {0};

    char *p1 = a;
    char *p2 = b;
    while(*(p1)!='\0')
    {
        *p2++ = *p1++;
    }
    *p2 = '\0';
    cout<<b<<endl;
    */

   /*
    使用%c是可以输出'\0'之后的内容的
    char a[] = "abc\0def";
    cout<<a<<endl; 
    for(int i  = 0;i<7;i++)
        printf("%c",*(a+i));
    cout<<endl;
    cout<<*(a+4)<<endl;
    printf("%s",a);
    */
   /*字符串使用指针赋值方法2
   char a[] = "abcdef";
   char b[] = {0};
   char *p1 = a;
   char *p2 = b;
   while((*p2++=*p1++)!='\0');
   cout<<b<<endl;
   */

    /*
    char *a = "123";
    char str[10] = "123";
    str = "123";//此处是错误的，因为数组名str是常量，不可以被赋值
    cout<<str<<endl;
    */

    // char str[100];
    // scanf("%s",str);
    // cin>>str;
    // char *a;
    // a = str;
    // cin>>a;//这样的话相当于是scanf("%s",str);
    //a = "123";//此处的做法是有问题的，因为这样相当于改变了str，而str是常量不可以变化，因此会出现错误
    // cout<<a<<endl;
    //  cout<<str<<endl;

    // char a[] = {"123"};
    // cin>>a;
    // cout<<a<<endl;
    // char b[] = {};
    // printf("%o\n",a);
    // printf("%o\n",b);

    // int (*p)(int a,int b);
    // p = max;
    // cout<<(*p)(1,2)<<endl;

    //指向一维数组的指针
    // int a[2][4] = {1,2,3,4,5,6,7,8};
    // int (*p)[4] = a+1;
    // cout<<(*p)[1]<<endl;

    char *arr[4];
    // cout<<arr<<endl;
    // cout<<arr+1<<endl;
    // cout<<arr+5<<endl;
    for(int i = 0;i<4;i++)
    {
        char str[100];
        cin>>str;
        arr[i] = str;
    //    cout<<arr[i]<<endl;
    }
    
    // for(int i =0;i<4;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }

    system("pause");
}