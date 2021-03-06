/*
    OBI 2017 - Programação Nível 1 - Fase 3 - Bits
    
    Assunto: Dynamic Programming
    Complexidade: O(n)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3+10, mod = 1e9+7;

int n, k;  ll dp[maxn];

int main()
{
	scanf("%d %d", &n, &k);

	dp[0] = 1;

	for(int i = 1 ; i <= n ; ++i)
	{
		if(i < k) dp[i] = (2 * dp[i - 1]) % mod;
		
		else if(i == k) dp[i] = (2 * dp[i - 1] - 1) % mod;
		
		else dp[i] = (2 * dp[i - 1] - dp[i - k - 1] + mod) % mod;
	}

	printf("%lld\n", dp[n]);
	
	return 0;
}