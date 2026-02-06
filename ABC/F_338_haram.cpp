#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<ll,pii> plii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=20;
int n,m;
vector<pii> adj[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v}); 
    }
    vector dp((1<<n),vector<ll>(n, 1e18));
    priority_queue<plii,vector<plii>,greater<plii>> pq;
    rep(i,0,n) {
        dp[(1<<i)][i] = 0;
        pq.push({0ll,{(1<<i),i}});
    }
    while(sz(pq)) {
        auto [d, sl] = pq.top(); pq.pop();
        auto [s, last] = sl;
        if(dp[s][last]<d) continue;
        for(auto [w,v]: adj[last]) {
            int sv = s | (1<<v);
            ll dv = d + w;
            if(dp[sv][v] > dv) {
                dp[sv][v] = dv;
                pq.push({dv, {sv,v}});
            }
        }
    }
    ll ans = 1e18;
    rep(i,0,n) {
        min_self(ans, dp[(1<<n)-1][i]);
    }
    if(ans == 1e18) {
        cout <<"No\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}