/*
	OBI 2014 - Programação Nível Júnior - Fase 1 - Flíper
	
	Assunto: Estruturas de Decisão

	Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

int p, r;

int main()
{
    scanf("%d%d", &p, &r);

    if(p == 0 && (r == 0 || r == 1)) { printf("C\n"); }
    else
    {
        if(r == 0) { printf("B\n"); }
        else { printf("A\n"); }
    }

    return 0;
}