#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e3+10;

int n, m;
int a[MAXN], b[MAXN], r[MAXN];
int main(){
	
	scanf("%d%d", &n, &m);

	for(int i=1;i<=n;++i)
		scanf("%d", &a[i]);
	
	for(int i=1;i<=m;++i)
		scanf("%d", &b[i]);
	
	for(int i=max(n, m);i>=1;--i){
		r[i]+=a[i]+b[i];
		if(r[i]>1){
			r[i]-=2;
			r[i-1]+=1;
		}
	}
	int k=1;
	for(int i=1;i<=max(n, m);++i) 
		if(r[i])
			k=i;
	
	for(int i=1;i<=k;++i) printf("%d ", r[i]);
	printf("\n");

	return 0;
}