/*
    OBI 2016 - Programação Nível 1 - Fase 2 - Arco e Flecha
    
    Assunto: BIT e Compressão de Coordenadas
    Complexidade: O(n * log n)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e+5, maxt = 131072;

struct point
{
	ll d;	int id;

	point(){};
	
	point(ll d_, int id_) { d = d_; id = id_; }

	bool operator<(const point& o) const { return (d < o.d); }
};

int n, k, v[maxn];  point comp[maxn];  ll tree[maxt];

ll query(int idx)
{
	ll sum = 0LL;

	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

void up(int idx, int val)
{
	while(idx <= k)
	{
		tree[idx] += val;
		idx += (idx&-idx);
	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0 ; i < n ; ++i)
	{
		ll u, v;  scanf("%lld%lld", &u, &v);

		ll a = (u * u) + (v * v);  comp[i] = point(a, i);
	}

	sort(comp, comp + n);
	
	ll D = -1LL, resp = 0LL;
	
	for(int i = 0 ; i < n ; ++i)
	{
		if(comp[i].d != D) { k++;  D = comp[i].d; }

		v[comp[i].id] = k;
	}
	
	for(int i = 0 ; i < n ; ++i)
	{
		resp += query(v[i]);
		up(v[i], 1);
	}

	printf("%lld\n", resp);  return 0;
}