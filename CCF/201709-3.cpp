#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
string s, str;
bool key;//key的作用在于区分是前面部分还是后面部分 
map<string, string> json;

string handle(string str, string s)
{
    if (s.empty())
    {
        return str;//如果str不存在那么就输出not exist 
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            continue;//遇到空格就继续 
        }
        else if (s[i] == '{')//以“{”和 “，”结尾都要看成是新的开始 
        {
            json[str] = "OBJECT";
            key = true;
        }
        else if (s[i] == '}')//是为了防止多层嵌套  
        {
            int i;
            for (i = str.size() - 1; i >= 0; i--)
            {
                if (str[i] == '.')
                {
                    break;
                }
            }
            if (i < 0)//如果 
            {
                str = "";
            }
            else
            {
                str = str.substr(0, i);
            }
        }
        else if (s[i] == ':')
        {
            key = false;
        }
        else if (s[i] == ',')//标志一行的结束 
        {
            key = true;
        }
        else if (s[i] == '"')//这么做是为了在有object的情况下使得连续 
        {
            string temp;
            for (i = i + 1; i < s.size(); i++)
            {
                if (s[i] == '\\')
                {
                    i++;
                    temp += s[i];//转译字符 
                }
                else if (s[i] == '"')
                {
                    break;//第二个‘”’结束 
                }
                else
                {
                    temp += s[i];
                }
            }
            if (key)//判断是否是object类型 
            {
                if (str == "")
                {
                    str = temp;//wocao  原来是从这里来的str   
                }
                else
                {
                    str += '.' + temp;
                    cout<<"str::::    "<<str<<endl; 
                }
            }
            else
            {
                json[str] = "STRING " + temp;
                int i;
                for (i = str.size() - 1; i >= 0; i--)
                {
                    if (str[i] == '.')
                    {
                        break;
                    }
                }
                if (i < 0)
                {
                    str = "";
                }
                else
                {
                    str = str.substr(0, i);//留给下一个object只带有前缀 
                }
            }
        }
    }
    
    	cout<<"str:"<<str<<"  "<<"s:"<<s<<endl;
    return str;
}

int main()
{
    std::ios::sync_with_stdio(false);//消除缓存 
    cin >> n >> m;
    cin.get();//可以接收空格 

    while (n--)
    {
        getline(cin, s);//读取的是cin输入流并且存储在s中 
        str = handle(str, s);
        cout<<"str:                      "<<str<<endl;
    }
    
    while (m--)
    {
        cin >> s;
        cout << (json[s] == "" ? "NOTEXIST" : json[s]) << endl;
    }
    return 0;
}

