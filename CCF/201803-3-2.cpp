#include <bits/stdc++.h>
using namespace std;
struct regulation{
    string name;
    vector<string> regv;
    regulation(string a,vector<string> v):name(a),regv(v){}//这样初始化之后就可以直接进行复制操作 
};
vector<regulation> regulations;
vector<string> str2regv(string str){ //返回是是一个vector<string> 
    vector<string> res;
    str=str.substr(1,str.size()-1);//返回值为去掉去第一个‘/ ’的字符串 
    res.push_back("/");
    size_t pos=str.find("/");
    while(pos!=string::npos){
        res.push_back(str.substr(0,pos));
        res.push_back("/");
        str=str.substr(pos+1);
        pos=str.find("/");
    }
    if(str.size()) res.push_back(str);
    
    cout<<"res: ";
    for(int i =0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl; 
    return res;
}
void urlmap(string str){
    vector<string> v=str2regv(str);//输入的检测数据 
    for(size_t i=0;i<regulations.size();++i){
        vector<string> &r=regulations[i].regv;
        string res=regulations[i].name;//开始的时候就让name位于前面 
        size_t lr=r.size(),lv=v.size(),j=0,k=0;
        while(j<lr&&k<lv){
            if(r[j]==v[k]){//先匹配相同的元素   这个的作用也在于匹配‘/’ 
                ++j,++k;continue;
            }
            if(r[j]=="<path>"){
                if(v[lv-1]=="/") break;//如果路径的最后一个为‘/’则为非法路径是404 
                res+=" ";
                while(k<lv){
                    res+=v[k++];
                }
                cout<<res<<endl;
                return;
            }else if(r[j]=="<int>"){
                string num;
                bool tag=1;
                for(size_t l=0;l<v[k].size();++l){
                    if(isdigit(v[k][l])) num+=v[k][l];//isdigital  判断是否为数字 
                    else {
                        tag=0;break;
                    }
                }
                if(tag==0) break;
                size_t uz=0;
                while(num[uz]=='0'&&uz<num.size()-1) ++uz;//把0除掉 
                res+=" "+num.substr(uz,num.size()-uz);
            }else if(r[j]=="<str>"){
                res+=" "+v[k];
            }else break;
            ++j;++k;
        }
        if(j==lr&&k==lv){
            cout<<res<<endl;
            return;//直接跳出函数 
        }
    }
    cout<<"404"<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string regstr,name;//regstr为规则，name为姓名 
        cin>>regstr>>name;
        regulations.push_back(regulation(name,str2regv(regstr)));
    }
    while(m--){
        string str;
        cin>>str;
        urlmap(str);
    }
    return 0;
}

