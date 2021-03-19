/*
	COCI 2016/2017 Contest #2 - Task Prosjecni

	WARNING!! This code isn't the full solution, it's only taking 24 points.

	Solution by Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);  cin >> n;

	if(n % 2)
	{
		for(int i = 1 ; i <= n * n ; ++i) { cout << i << " \n"[i % n == 0]; }
	}
	else { cout << "-1\n"; }

	return 0;
}