/*
	OBI 2015 - Programação Nível 1 - Fase 2 - Capitais
	
	Assunto: DFS - Busca em Profundidade 
	Complexidade: O(N + M)

	Solução por Samyra Almeida
*/

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10, inf = 1e9;

int n, h[maxn], ans = inf;
vector<int> graph[maxn];

void dist(int u, int f)
{
	h[u] = (graph[u].size() == 1)? 1 : inf;

	int a = inf;

	for(int v: graph[u])
	{
		if(v == f) continue;

		dist(v, u);

		h[u] = min(h[u], h[v] + 1);
		ans = min(ans, h[v] + a);
		a = min(h[v], a);
	}

	if(a != inf && graph[u].size() == 1) ans = min(ans, a);
}
int main()
{
	cin >> n;

	for(int i = 1 ; i < n ; ++i) 
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dist(1, -1);

	cout << ans << "\n";
}