#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int x1, y1, x2, y2;
	scanf("%d", &n);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	n/=2;
	
	if((x1<=n && x2>n) || (x2<=n && x1>n) || (y1<=n && y2>n) || (y2<=n && y1>n)) printf("S\n");
	else printf("N\n");

	return 0;
}