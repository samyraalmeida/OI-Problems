/*
	OBI 2015 - Programação Nível 2 - Fase 2 - Cálculo
	
	Assunto: Soma de dois números na base 2
	Complexidade: O(max(N, M))

	Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int n, m, a[maxn], b[maxn], r[maxn];

int main()
{	
	scanf("%d%d", &n, &m);

	for(int i = 1 ; i <= n ; ++i) scanf("%d", &a[i]);
	
	for(int i = 1 ; i <= m ; ++i) scanf("%d", &b[i]);
	
	for(int i = max(n, m) ; i >= 1 ; --i)
	{
		r[i] += a[i] + b[i];

		if(r[i] > 1) { r[i] -= 2;  r[i - 1] += 1; }
	}
	
	int k = 1;

	for(int i = 1 ; i <= max(n, m) ; ++i) { if(r[i]) { k = i; } }
	
	for(int i = 1 ; i <= k ; ++i) printf("%d ", r[i]);
	
	printf("\n");  return 0;
}