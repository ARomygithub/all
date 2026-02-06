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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
const ll mod = 998244353;
int n,t;
ll dp[mxn][3];
vector<int> adj[mxn];

void dfs(int u, int p=-1) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    dp[u][2] = 0;
    ll pi0 = 1ll;
    ll pi1 = 1ll;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        pi0 = pi0*dp[v][0]%mod;
        pi1 = pi1*(dp[v][0]+dp[v][1])%mod;
    }
    dp[u][0] = pi0;
    dp[u][1] = pi1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dp[u][2] = (dp[u][2] + dp[v][2])%mod;
        dp[u][2] = (dp[u][2] + dp[v][1])%mod;
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    ll ans = 0;
    rep(i,0,3) {
        ans = (ans+ dp[0][i])%mod;
    }
    cout <<ans <<"\n";
    rep(i,0,n) {
        adj[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}