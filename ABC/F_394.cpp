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

const int mxn=2e5;
int n;
int dp[mxn][3];
vi adj[mxn];
int ans = 0;

void dfs(int u, int p) {
    vi ve;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        ve.push_back(max(1,dp[v][1]));
    }
    sort(all(ve));
    if(sz(ve)) {
        dp[u][0] = ve.back()+1;
        max_self(ans, dp[u][0]);
    }
    if(sz(ve)>=3) {
        dp[u][1] = 1 + ve[sz(ve)-1]+ve[sz(ve)-2]+ve[sz(ve)-3];
    }
    if(sz(ve)>=4) {
        dp[u][2] = dp[u][1] + ve[sz(ve)-4];
        max_self(ans, dp[u][2]);
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
    if(ans<=4) {
        cout <<"-1\n";
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