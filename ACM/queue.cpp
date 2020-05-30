#include <iostream>
#include <queue>

using namespace std;

bool inQueue[10003];
queue<int> memory;

int main()
{
    int m,n;
    cin>>m>>n;

    int cnt = 0;

    for(int i =0;i<n;i++)
    {
        int v;
        cin>>v;

        if(!inQueue[v])
        {
            ++cnt;
            memory.push(v);
            inQueue[v] = true;
            while(memory.size()>m)
            {
                inQueue[memory.front()] = false;
                memory.pop();
            }
        }
    }

    cout<<cnt<<endl;
    system("pause");
}