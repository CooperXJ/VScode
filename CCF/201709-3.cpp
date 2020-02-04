#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
string s, str;
bool key;//key����������������ǰ�沿�ֻ��Ǻ��沿�� 
map<string, string> json;

string handle(string str, string s)
{
    if (s.empty())
    {
        return str;//���str��������ô�����not exist 
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            continue;//�����ո�ͼ��� 
        }
        else if (s[i] == '{')//�ԡ�{���� ��������β��Ҫ�������µĿ�ʼ 
        {
            json[str] = "OBJECT";
            key = true;
        }
        else if (s[i] == '}')//��Ϊ�˷�ֹ���Ƕ��  
        {
            int i;
            for (i = str.size() - 1; i >= 0; i--)
            {
                if (str[i] == '.')
                {
                    break;
                }
            }
            if (i < 0)//��� 
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
        else if (s[i] == ',')//��־һ�еĽ��� 
        {
            key = true;
        }
        else if (s[i] == '"')//��ô����Ϊ������object�������ʹ������ 
        {
            string temp;
            for (i = i + 1; i < s.size(); i++)
            {
                if (s[i] == '\\')
                {
                    i++;
                    temp += s[i];//ת���ַ� 
                }
                else if (s[i] == '"')
                {
                    break;//�ڶ������������� 
                }
                else
                {
                    temp += s[i];
                }
            }
            if (key)//�ж��Ƿ���object���� 
            {
                if (str == "")
                {
                    str = temp;//wocao  ԭ���Ǵ���������str   
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
                    str = str.substr(0, i);//������һ��objectֻ����ǰ׺ 
                }
            }
        }
    }
    
    	cout<<"str:"<<str<<"  "<<"s:"<<s<<endl;
    return str;
}

int main()
{
    std::ios::sync_with_stdio(false);//�������� 
    cin >> n >> m;
    cin.get();//���Խ��տո� 

    while (n--)
    {
        getline(cin, s);//��ȡ����cin���������Ҵ洢��s�� 
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

