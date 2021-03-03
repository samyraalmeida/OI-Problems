#include <bits/stdc++.h>

using namespace std;

struct edge{
    int nd, w;
};

const int maxn = 2e5+10, inf = 1e9;

int n, anc[maxn][20], h[maxn], sz[maxn], mark[maxn], ans = 1e9, k, dt[maxn], tot;
edge best;

vector<int> centroid[maxn];
vector<edge> graph[maxn];

void siz(const int &u, const int &f)
{
    sz[u] = 1;

    for(edge e: graph[u])
    {
        if(e.nd == f || mark[v.nd]) continue;

        siz(e.nd, u);
        sz[u] += sz[e.nd];
    }
}

void split(const int &u, const int &f)
{
    int sf = tot - sz[u];

    for(edge e: graph[u])
    {
        if(e.nd == f || mark[v.nd]) continue;

        sf = max(sf, sz[e.nd]);

        split(e.nd, u);
    }

    best = min(best, {sf, u});
}

inline int find_centroid(const int &u)
{
    best = {0, inf};
    siz(u, u);

    tot = sz[u];
    split(u, u);

    return best.nd;
}

int solve(int u)
{
    int cent = find_centroid(u);
    mark[cent] = 1;

    for(edge e: graph[u])
    {    
        if(mark[e.nd]) continue;

        int node = solve(v.e);

        centroid[cent].push_back(node);
        centroid[node].push_back(cent);
    }

    return cent;
}

void dfs(int u, int f)
{
    for(int v: centroid[u])
    {
        if(v == f) continue;

        if(dt[u] + )

        dfs(v.F, u);
    }
}

int lca(int u, int v)
{
    if(h[u] < h[v]) swap(u, v);

    for(int i = 19 ; i >= 0 ; --i)
        if(h[u] - (1 << i) >= h[v]) u = anc[u][i];

    if(u == v) return u;

    for(int i = 19 ; i >= 0 ; --i) 
        if(anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];

    return anc[u][0];
}

unordered_map<int, int> kth;
vector<ii> guys;

int llca, hh, dd;

void dists(int u, int f, int c, int comp)
{   
    llca = lca(u, c), hh = h[u] + h[c] - 2*h[llca], dd = dt[u] - 2*dt[llca] + dt[c];
    
    guys.push_back({dd, hh});

    if(kth.count(k - dd)) ans = min(ans, kth[k - dd] + hh);

    for(int i = 0 ; i < centroid[u].size() ; ++i)
    {
        int v = centroid[u][i];
        if(v == f || mark[v]) continue;

        dists(v, u, c, comp);
    }
}

int cmp;

void sol(int u)
{
    kth.clear();
    cmp = 0;
    mark[u] = 1;
    kth[0] = 0;

    for(int v: centroid[u])
    {
        if(mark[v]) continue;

        dists(v, u, u, ++cmp);

        for(ii x: guys) 
        {
            if(kth.count(x.F)) kth[x.F] = min(kth[x.F], x.S);
            else kth[x.F] = x.S;
        }

        guys.clear();
    }

    for(int v: centroid[u])
    {
        if(mark[v]) continue;

        sol(v);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;

    for(int i = 1 ; i < n ; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        u++, v++;

        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    int ft = solve(1);

    memset(anc, -1, sizeof anc);

    h[1] = 1;
    dfs(1, -1); 

    for(int j = 1 ; j < 20 ; ++j)
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            if(anc[i][j - 1] != -1)
            {
                anc[i][j] = anc[anc[i][j - 1]][j - 1];
            }
        }
    }

    memset(mark, 0, sizeof mark);

    sol(ft);
    if(ans == inf) cout << -1 << "\n";
    else cout << ans << '\n';
}
