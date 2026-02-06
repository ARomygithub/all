#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pipi pair<int,pii>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m,s,t;
set<int> adj[mxn];

void solve() {
    cin >>n >>m;
    vector<bool> spec(n,0);
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        if(adj[v].find(u)!=adj[v].end()) {
            spec[v] = 1;
            spec[u] = 1;
        }
        adj[u].insert(v);
    }
    cin >>s >>t; s--,t--;
    vector<vector<int>> dp(n,vector<int>(3,1e9));
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
    dp[s][0] = 0;
    pq.push({0,{s,0}});
    while(sz(pq)) {
        auto [w,uc] = pq.top(); pq.pop();
        auto [u,c] = uc;
        if(dp[u][c]<w) continue;
        for(auto v: adj[u]) {
            if(spec[u] || spec[v]) {
                c = min(c+1,2);
            }
            if(w+1<dp[v][c]) {
                if(v==t && c==1 && w+1%3==2) continue;
                dp[v][c] = w+1;
                pq.push({dp[v][c],{v,c}});
            }
        }
    }
    int ans=1e9;
    if(dp[t][0]!=1e9 && dp[t][0]%3==0) {
        min_self(ans,dp[t][0]/3);
    }
    if(dp[t][1]!=1e9) {
        if(dp[t][1]%3==0) {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}