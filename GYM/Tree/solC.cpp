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

const int mxn=1e5;
int n;
vector<int> adj[mxn];
int dp[mxn][2];

void dfs(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dp[u][1] +=dp[v][0];
        dp[u][0] +=max(dp[v][0],dp[v][1]);
    }
}

void solve() {
    cin >>n;
    rep(i,0,n-1) {
        int u,v; cin >>u >>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    rep(i,0,n) {
        dfs(i,-1);
        max_self(ans,1ll*(n-1)*max(dp[0][0],dp[0][1]));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}