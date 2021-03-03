#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> ini, fim;

int main()
{
	cin >> n;

	for(int i = 0 ; i < n ; ++i)
	{
		string s;  cin >> s;
        
		ini[s]++;
	}

	for(int i = 1 ; i < n ; ++i)
	{
		string s;  cin >> s;

		fim[s]++;
	}

	for(auto u: ini)
	{
		string s = u.first;
		int q = u.second;

		if(q != fim[s])
		{
			cout << s << "\n";
			break;
		}
	}
}