#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6+10;

int n;
char u[maxn];
string a, b, s1, s2;

int main()
{
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i) scanf(" %c", &u[i]);
	if(n%2 == 0)
	{
		printf("NOT POSSIBLE\n");
		return 0;
	}
	
	int mid = (n-1)/2, p1 = -1, p2 = -1;

	bool ok1 = true, ok2 = true;

	for(int i = 0 ; i < mid ; ++i) a.push_back(u[i]);
	for(int i = mid ; i < n ; ++i) b.push_back(u[i]);
	
	for(int i = 0, j = 0; i < mid ; ++j, ++i)
	{
		if(u[i] != u[j+mid]) 
		{	if(p1 == -1 && u[i] == u[++j+mid]) p1 = j;
			else
			{	
				ok1 = false;
				break;
			}
		}
		s1 += a[i];
	}

	a.clear(); b.clear();

	for(int i = 0 ; i <= mid ; ++i) b.push_back(u[i]);
	for(int i = mid + 1 ; i < n ; ++i) a.push_back(u[i]);

	for(int i = 0, j = 0; i < mid ; ++j, ++i)
	{
		if(u[j] != u[i+mid]) 
		{	if(p2 == -1 && u[i+mid] == u[++j+mid]) p2 = j;
			else
			{
				ok2 = false;
				break;
			}
		}
		s2 += a[i];
	}

	if(!ok1 && !ok2) printf("NOT POSSIBLE\n");
	else
	{
		if(ok1 && ok2 && s1 != s2) printf("NOT UNIQUE");
		else if(ok1) for(int i = 0 ; i < s1.size() ; ++i) printf("%c", s1[i]);
		else for(int i = 0 ; i < s2.size() ; ++i) printf("%c", s2[i]);
		printf("\n");
	}

	return 0;
}