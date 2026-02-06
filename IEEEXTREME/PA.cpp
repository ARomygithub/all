#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<ll,int> pli;

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
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m >>k; k--;
    for(int i=0;i<m;i++) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[v].push_back({w,u});
    }
    vector<ll> dp(n,1e18);
    dp[k] = 0;
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,k});
    while(sz(pq)) {
        auto [w,u] = pq.top(); pq.pop();
        if(w>dp[u]) continue;
        for(auto [wi,v]: adj[u]) {
            if(dp[u]+wi<dp[v]) {
                dp[v] = dp[u]+wi;
                pq.push({dp[v],v});
            }
        }
    }
    ll ans=0;
    map<ll,int> mp;
    for(int i=0;i<n;i++) {
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