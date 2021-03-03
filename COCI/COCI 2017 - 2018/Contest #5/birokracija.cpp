#include <bits/stdc++.h>
	
using namespace std;
	
typedef long long ll;
const int maxn=2e5+10;
	
int n, m, in[maxn], qc[maxn];
ll resposta[maxn];
vector <int> graph[maxn];
	
int dfs(int u, int f)
{
	for(int v: graph[u])
	{
		if(v != f)
		{
			int qv = dfs(v, u); 
			
			qc[u] += qv;  resposta[u] += resposta[v] + qv;
		}
	}
	
	resposta[u]++;  qc[u]++;  return qc[u];
}
	
int main()
{
	cin >> n;
	
	for(int i = 2 ; i <= n ; ++i)
	{
		cin >> in[i];

		graph[i].push_back(in[i]);
		graph[in[i]].push_back(i);
	}
	
	dfs(1, 1);
	
	for(int i = 1 ; i <= n ; ++i) { cout << resposta[i] << " \n"[i == n]; }
	
	return 0;
}