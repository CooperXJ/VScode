#include <iostream>
using namespace std;

int main()
{
    int v1,v2,t,s,l;
    cin>>v1>>v2>>t>>s>>l;

    int R_l = 0;
    int T_l = 0;
    int R_t = 0;
    int R_wait = 0;
    int T_t = 0;
    while(R_l<l&&T_l<l){
        if(R_l-T_l>=t)
        {
            R_wait+=s;
            T_t+=s;
        }
        else
        {
            R_t++;
            T_t++;
        }

        R_l = R_t*v1;
        T_l = T_t*v2;
        //cout<<"R  "<<R_l<<"  R_time  "<<(R_t+R_wait)<<"  T   "<<T_l<<"   T_time"<<T_t<<endl;
        
    }

    //cout<<"R__time"<<R_t+R_wait<<endl;
    //cout<<"T_time"<<T_t<<endl;
    if((R_t+R_wait)==T_t&&T_l==l&&R_l==l)
    {
        cout<<"D"<<endl;
        cout<<T_t<<endl;
    }
    
    else if (T_l>=l) {//对于乌龟来说可能在兔子前面跑到终点，但是并不是用了兔子休息的所有时间
    //如果跑多的话需要减去相应的所花时间
        cout<<"T"<<endl;
        if(T_l>l)
        {
            cout<<T_t-(T_l-l)/v2<<endl;
        }
        else
            cout<<T_t<<endl;
    }
    else if(R_l>=l)
    {
        cout<<"R"<<endl;
        cout<<(R_t+R_wait)<<endl;
    }
    
      
    system("pause");
    return 0;
}