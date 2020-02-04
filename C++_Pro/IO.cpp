#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void test0()//他会一直等待EOF出现，否则会阻塞
{
    char ch;
    while((ch=cin.get())!=EOF)//Ctrl+Z相当于是EOF
    {
        cout<<ch<<endl;
    }

    char ch1;
    cin.get(ch1);//从缓冲区读一个字符
    char buf[256] = {0};
    cin.get(buf,256);//从缓冲区读一个字符串
    cin.getline(buf,256);//读取一行数据，不读换行字符
}

//ignore
void test1()
{
    char ch;
    cin.get(ch);
    cout<<ch<<endl;
    cin.ignore(2,'9');
    //忽略当前字符 （无参的情况下） 
    //ignore(10) 忽略缓冲区中的10个字符并且取出  
    //ignore(10,ch)
    //如果遇到ch之前有10个字符，则忽略缓冲区的10个字符，
    //如果之前没有10个字符则直接忽略到ch就不会往下忽略了

    cin.get(ch);
    cout<<ch<<endl;
}

//peek()
void test2()
{
    char ch;
    ch = cin.peek();//偷窥缓冲区，返回第一个字符 但是并没有输出缓冲区的字符
    if(ch>='0'&&ch<='9')
    {
        cin>>ch;//此处提取缓冲区的字符
        cout<<ch<<endl;//输出缓冲区的字符
    }
        
    else
    {
        cout<<"your input is not number!"<<endl;
    }
    
}

//putbcak()
void test3(){
    char ch;
    cin.get(ch);//取出缓冲区的字符

    if(ch>='0'&&ch<='9')
    {
        cin.putback(ch);//此处将提取出来的缓冲区字符放入原来其在缓冲区的位置
        cout<<ch<<endl;//输出缓冲区的字符
    }
        
    else
    {
        cout<<"your input is not number!"<<endl;
    }
    
}

//output
void test4(){
    cout<<"i"<<endl;
    cout.flush();

    cout.put('H').put('H').put('H')<<endl;
    int num = 10;
    cout<<oct<<num<<endl;
    cout<<hex<<showbase<<num<<endl;
}

int main()
{
    test4();
    system("pause");
}