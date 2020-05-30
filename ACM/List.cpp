#include <iostream>
#include <list>
using namespace std;

bool vis[100003];
list<int> stus;
list<int>::iterator pos[100003];

int main()
{
    int n;
    cin>>n;
    stus.push_front(1);
    pos[1] = stus.begin();//将1装入队列中

    for(int i =2;i<=n;i++)
    {
        int k,p;//k为基准元素 p为该基准元素的左边还是右边
        cin>>k>>p;
        if(p==0)//左边
        {
            pos[i] = stus.insert(pos[k],i);//insert  插入后iter指向新插入的元素 如果直接插入的话就会将原来的位置的元素向后挤一位
        }
        else//右边
        {
            list<int>::iterator it = pos[k];
            ++it;
            pos[i] = stus.insert(it,i);
        }
    }

    int m;
    cin>>m;
    for(int i =0;i<m;i++)
    {
        int x;
        cin>>x;
        if(!vis[x])
        {
            stus.erase(pos[x]);
            vis[x] = true;
        }
    }

    for(list<int>::iterator it = stus.begin();it!=stus.end();it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    // list<int> l;
    // l.insert(l.begin(),1);
    // l.insert(++l.begin(),2);
    // for(list<int>::iterator it = l.begin();it!=l.end();it++)
    // {
    //     cout<<*it<<" ";
    // }
    system("pause");

    return 0;
}