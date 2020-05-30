#include <iostream>
#include <stack>

using namespace std;

stack<bool> bracket;
char s[257];

int main()
{
    cin>>s;
    bool flag = true;

    for(int i =0;s[i]!='@';++i)
    {
        if(s[i]=='(')
        {
            bracket.push(true);
        }
        else if(s[i]==')')
        {
            if(bracket.empty())//如果在这之前没有遇到'('那么栈里面就是空的，直接显示错误即可
            {
                flag = false;
                break;
            }
            bracket.pop();//如果遇到匹配的括号，那么需要删掉栈里面的内容
        }
    }

    if(!bracket.empty())//如果全部匹配那么所有的栈就为空
    {
        flag = false;
    }

    printf("%s\n",flag?"Yes":"No");

    system("pause");
    return 0;
}