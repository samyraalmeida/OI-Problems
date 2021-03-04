#include <bits/stdc++.h>
#define S second
#define F first

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int MAXN=1e2+10, INF=0x3f3f3f3f;

int n;
int m[MAXN][MAXN], dp[MAXN][MAXN];

void bfs(int x, int y){
	memset(dp, INF, sizeof dp);
	dp[x][y]=0;

	priority_queue<iii> row;
	row.push(iii(0, ii(x, y)));
	while(!row.empty()){

		int D=row.top().F, a=row.top().S.F, b=row.top().S.S;
		row.pop();
		if(D>dp[a][b]) continue;
		for(int i=-1;i<=1;++i){
			for(int j=-1;j<=1;++j){
				if(j!=0 && i!=0) continue;

				if(m[a+i][b+j]!=-1 && dp[a+i][b+j]>dp[a][b]+m[a+i][b+j]){
					dp[a+i][b+j]=dp[a][b]+m[a+i][b+j];
					row.push(iii(-dp[a+i][b+j], ii(a+i, b+j)));
				}
			}
		}
	}
}

int main(){

	scanf("%d", &n);
	memset(m, -1, sizeof m);
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d", &m[i][j]);


	bfs(1,1);
	printf("%d\n", dp[n][n]);
	return 0;
}