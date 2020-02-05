#include <iostream>
#include <math.h>
#include <string>
using namespace std;


//string也是容器

//string遍历元素
void show()
{
    // s[i]访问越界的话直接报错
    // s.at(i) 访问越界直接抛异常
}

//拼接操作
void test0()
{
    string s = "abc";
    s+="def";
    cout<<s<<endl;

    s.append("ghi");//拼接到尾部
}

//查找操作
void test1()
{
    string s = "abcdefghijkl";
    int pos  = s.find("fg");//查找第一个出现位置
    cout<<pos<<endl;

    //查找最后一次出现的位置
    pos = s.rfind("fg");
    cout<<pos<<endl;
}

//string替换
void test2()
{
    string s = "abcdefghij";
    s.replace(0,2,"111");//从0列开始替换2个字符
    cout<<s<<endl;
}

//string比较
void test3()
{
    string s1 = "abcd";
    string s2 = "abce";
    cout<<s1.compare(s2)<<endl;//返回1 > 返回-1 < 返回0  相等
}

//string子串
void test4()
{
    string s = "abcdefg";
    string mysubstr = s.substr(1,3);
    cout<<mysubstr<<endl;
}

//string插入与删除
void test5()
{
    string s = "abcdefg";
    s.insert(3,"111");
    cout<<s<<endl;

    s.erase(0,3);//删除
    cout<<s<<endl;
}

//string类型与char *转换
void test6()
{
    //string转为char *
    string str = "123";
    const char *s = str.c_str();

    //char *转为string
    char *ss = "345";
    string ss1(ss);
    cout<<ss1<<endl;

}
int main()
{
    test6();
    system("pause");
}