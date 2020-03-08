#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
    string str = "123";
    str.append("123");

    str.push_back('1');

    //如果想要使用append后面加上字符的话，需要表明个数因为他需要先将字符转换成字符串再进行拼接的
    str.append(5,'.');
    str.append(1,'t');
    cout<<str<<endl;

    str+="444444";
    cout<<str<<endl;
    
    //str.push_back只可以增加字符，无法增加字符串
    str.push_back('s');
    cout<<str<<endl;
    system("pause");
}