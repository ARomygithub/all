#include <bits/stdc++.h>
using namespace std;

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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m,t;
map<int,int> adj[mxn];
ll ans = 2e18;
using piii = pair<pii,int>;
using pli = pair<ll,int>;

void coba(int st, int en) {
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<pli> dp(n,{1e18,-1});
    dp[st] = {0,-1};
    pq.push({0,st});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u].fi>d) continue;
        for(auto& [v,w]: adj[u]) {
            if(dp[v].fi > d+w) {
                dp[v] = {d+w, u};
                pq.push({d+w,v});
            }
        }
    }
    ll cur = dp[1].fi;
    int u0 = 1;
    vector<piii> er;
    while(u0!=st) {
        auto [d,v] = dp[u0];
        er.push_back({{u0,v},adj[u0][v]});
        u0 = v;
    }
    for(auto& [uv,w]: er) {
        auto [u,v] = uv;
        adj[u][v] = (w+1)/2; 
        adj[v][u] = (w+1)/2;
    }
    vector<ll> dp2(n,1e18);
    dp2[1] = 0;
    pq.push({0,1});
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp2[u]>d) continue;
        for(auto& [v,w]: adj[u]) {
            if(dp2[v] > d+w) {
                dp2[v] = d+w;
                pq.push({dp2[v],v});
            }
        }
    }
    cur += dp2[en];
    min_self(ans, cur);
    for(auto& [uv,w]: er) {
        auto [u,v] = uv;
        adj[u][v] = w;
        adj[v][u] = w;
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    coba(0,2);
    // coba(2,0);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}