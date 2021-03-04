#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int n;

ll cross(const pll& o, const pll& a, const pll& b){
	return (a.F-o.F)*(b.S-o.S)-(b.F-o.F)*(a.S-o.S);
}

vector<pll> v;

int main(){

	scanf("%d", &n);

	for(int i=0;i<n;++i){

		ll x, h;
		scanf("%lld%lld", &x, &h);
		v.push_back({x, h});
	}
	
	int k=0;
	sort(v.begin(), v.end());

	vector<pll> H(2*n);

	for(int i=0;i<n;++i){
		while(k>=2 && cross(H[k-2], H[k-1], v[i])>=0){
			k--;
		}
		H[k++]=v[i];
	}

	printf("%d\n", k-1);
	return 0;
}