#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10, inf = 0x3f3f3f3f;

int n, q, seg[4 * maxn];

void upd(int i, int x, int u=1, int l = 1, int r = n)
{
	if(l==r) { seg[u] = x; return; }

	int mid = (l +r ) >> 1;

	if(i <= mid) upd(i, x, 2 * u, l, mid);
	else upd(i, x, 2 * u + 1, mid + 1, r);
	
	seg[u] = min(seg[2 * u], seg[2 * u + 1]);
}

int search_seg(int b, int x, int u = 1, int l = 1, int r = n)
{
	if(seg[u] > x) return inf;
 
	if(b > r) return inf;
 
	if(l == r) return l;
 
	int mid = (l + r) >> 1;
 
	if(l < b) return min(search_seg(b, x, 2 * u, l, mid), search_seg(b, x, 2 * u + 1, mid + 1, r));
 
	if(seg[2 * u] <= x) return search_seg(b, x, 2 * u, l, mid);
 
	return search_seg(b, x, 2 * u + 1, mid + 1, r);
}
 
int main()
{
	scanf("%d%d", &n, &q);

	memset(seg, inf, sizeof seg);

	for(int i = 0 ; i < q ; ++i)
	{
		char c;  int x, a;  scanf(" %c %d %d", &c, &x, &a);
 
		if(c=='M') { upd(a, x); }
		else
		{
			int k = search_seg(a, x);

			if(k >= inf) printf("-1\n");
			else printf("%d\n", k);
		}
	}
 
	return 0;
}