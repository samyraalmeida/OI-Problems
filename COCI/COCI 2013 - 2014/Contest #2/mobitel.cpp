#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int v[15];
map<int, int> tec;
map<char, ii> t;

void make()
{
	t['a'] = ii(2, 1);
	t['b'] = ii(2, 2);
	t['c'] = ii(2, 3);
	t['d'] = ii(3, 1);
	t['e'] = ii(3, 2);
	t['f'] = ii(3, 3);
	t['g'] = ii(4, 1);
	t['h'] = ii(4, 2);
	t['i'] = ii(4, 3);
	t['j'] = ii(5, 1);
	t['k'] = ii(5, 2);
	t['l'] = ii(5, 3);
	t['m'] = ii(6, 1);
	t['n'] = ii(6, 2);
	t['o'] = ii(6, 3);
	t['p'] = ii(7, 1);
	t['q'] = ii(7, 2);
	t['r'] = ii(7, 3);
	t['s'] = ii(7, 4);
	t['t'] = ii(8, 1);
	t['u'] = ii(8, 2);
	t['v'] = ii(8, 3);
	t['w'] = ii(9, 1);
	t['x'] = ii(9, 2);
	t['y'] = ii(9, 3);
	t['z'] = ii(9, 4);
}

int main()
{
	for(int i = 1 ; i <= 9; ++i)
	{
		int x;  cin >> x;
		tec[x] = i;
	}

	string s;  cin >> s;

	make();

	int val = -1;
	
	for(int i = 0 ; i < s.size() ; ++i)
	{
		char c = s[i];  int a = t[c].first, b = t[c].second;

		if(a == val) cout << '#';
		else val = a;

		for(int j = 0 ; j < b ; ++j) cout << tec[a];
	}
	
	cout << '\n';  return 0;
}