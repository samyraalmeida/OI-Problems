#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

int n, p;
bool ck[maxn];
int ct[maxn];

int main()
{
	cin >> p >> n;
	bool ok = false;

	for(int i = 1 ; i <= n ; ++i)
	{
		int x;
		cin >> x;
		ck[x] = 1;
		ct[x]++;
	}

	for(int i = 1 ; i <= min(p,n) ; ++i)
	{
		if(ck[i] == 0)
		{
			cout << "N\n";
			return 0;
		}
	}
	//cout << "\n\n";

	for(int i = 2 ; i <= min(p, n) ; ++i)
	{	//cout << at << " "<< i << " " << ct[i] << "\n";
		if(ct[i] != ct[i-1])
		{
			//cout << "oi krl\n";
			if(ct[i] == ct[i-1] - 1 && ok == 0)
			{
				ok = 1;
			}else{
				cout << "N\n";
				return 0;
			}
		}
	}
	cout << "S\n";

	return 0;
}