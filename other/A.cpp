#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pll pair<ll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m,k;
vector<pii> adj[mxn+1];

void solve() {
    cin >>n >>m >>k;
    for(int i=0;i<m;i++) {
        int u,v,w; cin >>u >>v >>w;
        adj[v].push_back({w,u});
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> dp(mxn+1,1e18);
    dp[k] = 0;
    pq.push({0,k});
    while(sz(pq)) {
        auto [w,u] = pq.top(); pq.pop();
        if(w>dp[u]) continue;
        for(auto [wi,vi]: adj[u]) {
            if(dp[u]+wi<dp[vi]) {
                dp[vi] = dp[u]+wi;
                pq.push({dp[vi],vi});
            }
        }
    }
    ll ans=0;
    map<ll,int> mp;
    for(int i=1;i<=n;i++) {
        // cout <<dp[i] <<"\n";
        if(dp[i]==1e18) continue;
        ans +=mp[dp[i]];
        mp[dp[i]]++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}