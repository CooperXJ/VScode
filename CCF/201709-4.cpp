#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V 1001
using namespace std;

int N, M;
vector<int> G[MAX_V], rG[MAX_V];
vector<int> postorder;
bool used[MAX_V];
int label[MAX_V]; // ÿһ���ڵ�����ǿ��ͨ�����ı��
int sccv[MAX_V]; // ÿһ��ǿ��ͨ������һ������
int nparent[MAX_V], nchild[MAX_V];  // ÿһ���ڵ㸸/��ǿ��ͨ�������� 

// ����ͼ�ĺ������ 
void dfs(int u) {
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if(!used[v]) {
            used[v] = true;
            dfs(v);
        }
    }
    postorder.push_back(u);
}

int rdfs(int u, int l) {
    label[u] = l;
    for(int i=0; i<rG[u].size(); i++) {
        int v = rG[u][i];
        if(!used[v]) {
            used[v] = true;
            rdfs(v, l);
        }
    }
}

// Kosaraju�㷨 �ֽ�ǿ��ͨ���� 
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
    for(int n=N-1; n>=0; n--) {
        int v = postorder[n];
        if(!used[v]) {
            l++;
            used[v] = true;
            rdfs(v, l);
            sccv[l] = v;
        }
    }
    cout<<"l: "<<l;
    return l;
}

// ͳ��u����ǿ��ͨ�����ܹ����������ǿ��ͨ���� 
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
        rG[b].push_back(a);
    }
    
    int numc = SCC();
    
    // ͳ��ÿһ�����㸸ǿ��ͨ�������� 
    for(int i=1; i<=numc; i++) {
        fill(used, used+MAX_V, 0);
        int v = sccv[i];
        used[v] = true;
        dfs2(v, label[v], nparent, G);
    }
    
    // ͳ��ÿһ��������ǿ��ͨ�������� 
    for(int i=1; i<=numc; i++) {
        fill(used, used+MAX_V, 0);
        int v = sccv[i];
        used[v] = true;
        dfs2(v, label[v], nchild, rG);
    }
    
    int cnt = 0;
    for(int n=1; n<=N; n++) {
        // �����ǿ��ͨ������������ǿ��ͨ����������һ������ǿ��ͨ�������� 
        if(nparent[n]+nchild[n]+1==numc) cnt++;
    }
    cout << cnt;
}
