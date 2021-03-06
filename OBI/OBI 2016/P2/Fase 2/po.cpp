/*
    OBI 2016 - Programação Nível 2 - Fase 2 - Pô, que mão
    
    Assunto: Operações Básicas e Noções elementares de ordenação
    Complexidade: O(1)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

int p[5], P;

int main()
{
	scanf("%d%d%d%d", &P, &p[0], &p[1], &p[2]);

	sort(p, p + 3);

	int sum = 0, ans = 0;
	
	for(int i = 0 ; i < 3 ; ++i)
	{
		if(sum + p[i] <= P) { ans++; sum += p[i]; }
	}

	printf("%d\n", ans);  return 0;
}