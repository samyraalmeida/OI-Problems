/*
    OBI 2018 - Programação Nível 2 - Fase 2 - Wifi 
    
    Assunto: Sweep Line and Map
    Complexidade: O(n * log n)
    
    Solução por Samyra Almeida
*/

#include <bits/stdc++.h>
     
using namespace std;

int n;

struct line
{
	int x, hi, hf, t;

	bool operator<(const line& o) const { return x < o.x; }
};

vector<line> event;

int main()
{
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; ++i)
	{
		int xi, yi, xf, yf;
		scanf("%d %d %d %d", &xi, &yf, &xf, &yi);

		event.push_back({xi, yi, yf, 0});
		event.push_back({xf, yi, yf, 1});
	}

	int ans = 0;

	sort(event.begin(), event.end());
	
	map<int, int> ocup;
	
	for(int i = 0 ; i < event.size() ; ++i)
	{
		if(event[i].t==0)
		{
			ocup[event[i].hi] = 0;
			ocup[event[i].hf] = 1;
		}
		else
		{
			if(ocup[event[i].hi] == 0) ans++;
			
			auto it = ocup.find(event[i].hi);  it--;  it->second=1;

			ocup.erase(event[i].hi);
			ocup.erase(event[i].hf);
		}
	}

	printf("%d\n", ans);  return 0;
}