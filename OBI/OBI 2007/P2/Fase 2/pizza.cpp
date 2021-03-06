/*
    OBI 2007 - Programação Nível 2 - Fase 2 - Pizza
	
	Assunto: Dynamic Programming - Maximum Sum
    Complexidade: O(N)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, ans, b[maxn], s[maxn], v[maxn];

int main()
{
	scanf("%d", &n);

	for(int i = 0 ; i < n ; ++i) { scanf("%d", &v[i]); }

	for(int i = 0 ; i < n ; ++i)
	{
		s[i + 1] = s[i] + v[i];
		b[i + 1] = max(b[i], s[i + 1]);
	}

	for(int i = 0 ; i <= n ; ++i) { ans = max(ans, b[i] + s[n] - s[i]); }

	int t = 0;

	for(int i = 0 ; i < n ; ++i)
	{
		t = max(t + v[i], 0);
		ans = max(ans, t);
	}

	printf("%d\n", ans);  return 0;
}