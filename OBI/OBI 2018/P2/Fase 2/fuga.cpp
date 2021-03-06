/*
    OBI 2018 - Programação Nível 2 - Fase 2 - Fuga 
    
    Assunto: BIT e Compressão de Coordenadas
    Complexidade: O(n * log n)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {-2, 2, 0, 0};
int dy[] = {0, 0, -2, 2};

int n, m, xi, yi, xf, yf, ans, graph[15][15];

bool ck(int x, int y) { return (x >= 1 && y >= 1 && x <= n && y <= m && graph[x][y] == 0); }

void dfs(int x, int y, int k)
{
	graph[x][y] = 1;  k++;

	if(x == xf && y == yf) ans = max(ans, k);
	else
	{
		for(int i = 0 ; i < 4 ; ++i)
		{
			int kx = x + dx[i], ky = y + dy[i];

			if(ck(kx, ky)) dfs(kx, ky, k + 1);
		}
	}

	k--;  graph[x][y] = 0;
}

int main()
{	
	scanf("%d%d%d%d%d%d", &n, &m, &xi, &yi, &xf, &yf);

	for(int i = 2 ; i <= n ; i += 2) { for(int j = 2 ; j <= m ; j += 2) { graph[i][j] = 1; } }

	dfs(xi, yi, 0);

	printf("%d\n", ans); return 0;
}