/*
    OBI 2016 - Programação Nível 2 - Fase 2 - Falta uma 
    
    Assunto: Fatorial e operações básicas
    Complexidade: O(n * n!)
    
    Solução por Samyra Almeida
*/

#include <iostream>

using std::cin; using std::cout;

int n; long long fat = 1LL, dp[10];

int main()
{	
	cin >> n;

	for(int i = 2 ; i <= n ; ++i) fat *= i;

	for(int i = 1 ; i < fat ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			int num;  cin >> num;
			dp[j] += num;
		}
	}

	fat *= (n + 1);  fat >>= 1;

	for(int i = 1 ; i <= n ; ++i) cout << fat - dp[i] << ' ';

	cout << '\n';  return 0;
}