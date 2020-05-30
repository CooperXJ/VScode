#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V 1001
using namespace std;

int N, M;
vector<int> G[MAX_V], rG[MAX_V];
vector<int> postorder;
bool used[MAX_V];
int label[MAX_V]; // 每一个节点所属强连通分量的标号
int sccv[MAX_V]; // 每一个强连通分量的一个顶点
int nparent[MAX_V], nchild[MAX_V];  // 每一个节点父/子强连通分量个数 

// 生成图的后序遍历 
void dfs(int u) {
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if(!used[v]) {
            used[v] = true;
            dfs(v);
        }
    }
    postorder.push_back(u);
    
    cout<<"postorder:  ";
    for(int i =0;i<postorder.size();i++)
    {
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
}

int rdfs(int u, int l) {
    label[u] = l;//给每一组强连通分量打上标签  l为标签
    for(int i=0; i<rG[u].size(); i++) {
        int v = rG[u][i];
        if(!used[v]) {
            used[v] = true;
            rdfs(v, l);//只要在子树上面就打上同一个标签
        }
    }
}

// Kosaraju算法 分解强连通分量 
int SCC() {
    fill(used, used+MAX_V, 0);
    for(int n=1; n<=N; n++) {
        if(!used[n]) {
            used[n] = true;
            dfs(n);
        }
    }
    fill(used, used+MAX_V, 0);
    int l = 0;
    //从最底层的点开始遍历
    for(int n=N-1; n>=0; n--) {
        int v = postorder[n];
        if(!used[v]) {
            l++;//l是不变的  在每次rdfs的时候
            used[v] = true;
            rdfs(v, l);
            sccv[l] = v;//每一组强连通分量的顶点
        }
    }
    cout<<"l: "<<l<<endl;
    return l;
}

// 统计u所在强连通分量能够到达的其它强连通分量 
void dfs2(int u, int l, int (&nparent)[MAX_V], vector<int> (&G)[MAX_V]) {
    if(label[u] != l) nparent[u]++;
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if(!used[v]) {
            used[v] = true;
            dfs2(v, l, nparent, G);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int m=0; m<M; m++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);//邻接矩阵的逆矩阵
    }//创建邻接矩阵
    
    int numc = SCC();//返回强连通分量的个数
    
    // 统计每一个顶点父强连通分量个数 
    for(int i=1; i<=numc; i++) {
        fill(used, used+MAX_V, 0);
        int v = sccv[i];//v为每个强连通分量的顶点
        used[v] = true;
        dfs2(v, label[v], nparent, G);
    }
    
    // 统计每一个顶点子强连通分量个数 
    for(int i=1; i<=numc; i++) {
        fill(used, used+MAX_V, 0);
        int v = sccv[i];
        used[v] = true;
        dfs2(v, label[v], nchild, rG);
    }
    
    int cnt = 0;
    for(int n=1; n<=N; n++) {
        // 如果父强连通分量个数加子强连通分量个数加一等于总强连通分量个数 
        if(nparent[n]+nchild[n]+1==numc) cnt++;
    }
    cout << cnt<<endl;;
    system("pause");
}