#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10, maxl = 20, inf = 1e9;

typedef pair<int, int> ii;

int n, mark[maxn], sz[maxn], dt[maxn], ans = inf, h[maxn], anc[maxn][maxl], pai[maxn];
vector<int> graph[maxn], centroid[maxn];

void siz(int u, int f)
{
	sz[u] = 1;

	for(int v: graph[u])
	{
		if(v == f || mark[v]) continue;

		siz(v, u);

		sz[u] += sz[v];
	}
}

int tot;
ii best;

void split(int u, int f)
{
	int sf = tot - sz[u];

	for(int v: graph[u])
	{
		if(v == f || mark[v]) continue;

		sf = max(sf, sz[v]);

		split(v, u);
	}

	best = min(best, {sf, u});
}

int find_centroid(int u)
{
	best = {inf, 0};
	siz(u, u);

	tot = sz[u];
	split(u, u);

	return best.second;
}

int solve(int u)
{
	int cent = find_centroid(u);
	mark[cent] = 1;

	for(int v: graph[cent])
	{
		if(mark[v]) continue;

		int node = solve(v);
		centroid[cent].push_back(node);
		centroid[node].push_back(cent);
	}

	return cent;
}

void dfs(int u, int f)
{
	for(int v: graph[u])
	{
		if(v == f) continue;

		h[v] = h[u] + 1;
		anc[v][0] = u;

		dfs(v, u);
	}
}

int lca(int u, int v)
{
	if(h[u] < h[v]) swap(u, v);

	for(int i = maxl - 1 ; i >= 0 ; --i)
		if(h[u] - (1 << i) >= h[v]) u = anc[u][i];

	if(u == v) return u;

	for(int i = maxl - 1 ; i >= 0 ; --i)
		if(anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];

	return anc[u][0];
}

void dist(int u, int f, int c)
{
	dt[u] = (graph[u].size() == 1) ? h[u] + h[c] - 2*h[lca(u, c)] : inf;

	for(int v: centroid[u])
	{
		if(mark[v] || v == f) continue;

		dist(v, u, c);

		dt[u] = min(dt[u], dt[v]);
	}
}

void sol(int u)
{
	dist(u, u, u);
	
	mark[u] = 1;

	int d1 = inf, d2 = inf;

	for(int v: centroid[u])
	{
		if(mark[v]) continue;

		if(dt[v] < d1) d2 = d1, d1 = dt[v];
		else if(dt[v] < d2) d2 = dt[v];
	}

	if(graph[u].size() == 1)
	{
		if(dt[u] < d1) d2 = d1, d1 = dt[u];
		else if(dt[u] < d2) d2 = dt[u];
	}
	
	ans = min(ans, d1 + d2);

	for(int v: centroid[u])
	{
		if(mark[v]) continue;

		sol(v);
	}
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

	int ft = solve(1);

	memset(anc, -1, sizeof anc);
	
	h[1] = 1;
	dfs(1, -1);

	for(int j = 1 ; j < maxl ; ++j)
		for(int i = 1 ; i <= n ; ++i)
			if(anc[i][j - 1] != -1) anc[i][j] = anc[anc[i][j - 1]][j - 1];

	memset(mark, 0, sizeof mark);

	sol(ft);

	cout << ans << '\n';

	return 0;
}