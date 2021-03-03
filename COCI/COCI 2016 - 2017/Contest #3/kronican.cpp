#include <bits/stdc++.h>
    
using namespace std;
    
const int maxmask = (1<<20)+10, inf = 0x3f3f3f3f;
    
int n, k, m[30][30];
    
int dp[maxmask];
    
int solve(int mask, int qtd){
    
    if(dp[mask] != inf) return dp[mask];
    if(qtd >= k) return 0;
    
    for(int i = 0 ; i < n ; ++i){
        if(mask & (1<<i)) continue;
    
        for(int j = 0 ; j < n ; ++j){
            
            if(i == j) continue;
            if(mask & (1<<j)) continue;
    
            dp[mask] = min(dp[mask], m[i][j] + solve(mask | (1<<i), qtd+1));
        }
    }
    
    return dp[mask];
}

int main(){
    
    cin >> n >> k;
    
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> m[i][j];   
    
    memset(dp, inf, sizeof dp);
    
    k = n - k;
    cout << solve(0, 0) << "\n";
}