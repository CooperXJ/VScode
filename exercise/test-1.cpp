#include <iostream>
#include <vector>
const int maxdist = 9999;
using namespace std;

void Dijkstra(int n,int v,vector<int> &dist,vector<int> &pre,vector< vector<int> > &d) {
	vector<bool> s(n+1);

	for(int i =1; i<=n; i++) {
		dist[i] = d[v][i];
		if(dist[i]<maxdist)
			pre[i] = v;
		else
			pre[i] = 0;
	}

	s[v] = true;
	dist[v] = 0;

	for(int i =2; i<=n; i++) {
		int temp = maxdist;
		int best = v;
		for(int j =1; j<=n; j++) {
			if(!s[j]&&dist[j]<temp) {
				temp = dist[j];
				best = j;
			}
		}

		s[best] = true;

		for(int j =1; j<=n; j++) {
			if(!s[j]&&d[best][j]<maxdist) {
				int newdist = dist[best]+d[best][j];
				if(dist[j]>newdist) {
					dist[j] = newdist;
					pre[j] = best;
				}
			}
		}
	}
}

void printpath(vector<int> pre,int start,int final)
{
	cout<<start<<"->";
	for(int i =1;i<=pre.size()-1;i++)
	{
		if(pre[i]==start||pre[i]==0)//ɾ���������Լ���0�Ľڵ� 
		continue;
		else
		cout<<pre[i]<<"->";
	}
	cout<<final<<endl;	
}


int main() {
		int n, l;
    cout << "������������������";
    cin >> n >> l;
    vector< vector<int> > d(n+1, vector<int>(n+1));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][j] = maxdist;//���е���·����������Ϊmax 
    }
    
    int p, q, len;
    for (int i = 1; i <= l; ++i)
    {
        cin >> p >> q >> len;
        if (len < d[p][q])       // ���ر�
        {
            d[p][q] = len;      // pָ��q
            d[q][p] = len;      // qָ��p��������ʾ����ͼ
        }
    }
    
    vector<int> dist(n+1),pre(n+1);
    for (int i = 1; i <= n; ++i)
        dist[i] = maxdist;
    Dijkstra(n, 1, dist, pre, d);
    cout << "��1����n�����·������: " << dist[n] << endl;
    cout << "��1����n��·��Ϊ: ";
    printpath(pre, 1, n);
    return 0;
}
