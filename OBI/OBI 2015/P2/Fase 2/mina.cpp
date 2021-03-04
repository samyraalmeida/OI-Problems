/*
	OBI 2015 - Programação Nível 2 - Fase 2 - Mina

	Assunto: Dynamic Programming and BFS
	Complexidade: O((n * log n)

	Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;

typedef pair<int, int> ii;  typedef pair<int, ii> iii;

const int maxn = 1e2 + 10, inf=0x3f3f3f3f;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m[maxn][maxn], dp[maxn][maxn];

void bfs(int x, int y)
{
	memset(dp, inf, sizeof dp);
	dp[x][y] = 0;

	priority_queue<iii> row;
	row.push(iii(0, ii(x, y)));

	while(!row.empty())
	{
		int D = row.top().F, a = row.top().S.F, b = row.top().S.S;
		
		row.pop();
		
		if(D > dp[a][b]) continue;

		for(int i = 0 ; i < 4 ; ++i)
		{
			if(m[a + dx[i]][b + dy[i]]!=-1 && dp[a + dx[i]][b + dy[i]] > dp[a][b] + m[a + dx[i]][b + dy[i]])
			{
				dp[a + dx[i]][b + dy[i]]=dp[a][b] + m[a + dx[i]][b + dy[i]];
				row.push(iii(-dp[a + dx[i]][b + dy[i]], ii(a + dx[i], b + dy[i])));
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	memset(m, -1, sizeof m);
	
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			scanf("%d", &m[i][j]);

	bfs(1,1);  printf("%d\n", dp[n][n]);  return 0;
}