/*
    OBI 2016 - Programação Nível 2 - Fase 2 - Jardim de Infância
    
    Assunto: Geometria Computacional (Pontos, linhas e segmentos de linhas. pontos colineares, vetores paralelos e ortgonais, interseção de duas linhas)
	
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point { int x, y; };

point p[10];

ll dist (point a, point b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

bool ck (ll a, ll b) { return (a == b); }

bool col (point a, point b, point c)
{
	if((c.y - b.y) * (b.x - a.x) == (c.x - b.x) * (b.y - a.y)) return true;
	
	return false;
}

ll cross (point o, point a, point b) { return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x); }

int main ()
{
	for(int i = 1 ; i < 8 ; ++i) { scanf("%d%d", &p[i].x, &p[i].y); }

	ll d12 = dist(p[1], p[2]), d13 = dist(p[1], p[3]);
	ll d46 = dist(p[4], p[6]), d57 = dist(p[5], p[7]);
	ll d24 = dist(p[2], p[4]), d26 = dist(p[2], p[6]);
	ll d35 = dist(p[3], p[5]), d37 = dist(p[3], p[7]);

	if(ck(d12, d13) && ck(d46, d57))
	{
		if(ck(d26, d24+d46) && ck(d35+d57, d37))
		{
			if(col(p[2], p[4], p[5]) && col(p[4], p[5], p[3]))
			{
				ll d25 = dist(p[2], p[5]), d34 = dist(p[3], p[4]);

				if(ck(d25, d34) && ck(d24, d35))
				{
					ll d23 = dist(p[2], p[3]);
					ll d45 = dist(p[4], p[5]);

					if(d23 < d13 + d12 && d23 > d45)
					{
						ll c1 = cross(p[2], p[1], p[3]);
						ll c2 = cross(p[2], p[6], p[3]);
						
						if((c2 > 0 && c1 < 0) || (c2 < 0 && c1 > 0)) printf("S\n");
						else printf("N\n");
					
					}
					else printf("N\n");
				}
				else printf("N\n");
			}
			else printf("N\n");
		}
		else printf("N\n");
	}
	else printf("N\n");

	return 0;
}