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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e3;
int n,s,f,k;
int p[mxn];
bool havePerak[mxn];
int dp[mxn][mxn+1];
bool vis[mxn][mxn+1];
vector<pii> adj[mxn];

int dfs(int u, int ctPerak) {
    if(vis[u][ctPerak]) {
        return dp[u][ctPerak];
    }
    if(u==f) {
        return p[f];
    }
    for(auto [v,m]: adj[u]) {
        if(ctPerak>=m) {
            int temp = dfs(v,ctPerak-m+(havePerak[v]==1));
            if(temp!=-1) {
                max_self(dp[u][ctPerak], p[u]+temp);
            }
        }
    }
    vis[u][ctPerak] = 1;
    return dp[u][ctPerak];
}

void solve() {
    cin >>n >>s >>f;s--,f--;
    memset(dp,-1,sizeof dp);
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout <<dp[i][j];
    //     }
    // }
    for(int i=0;i<n;i++) {
        cin >>p[i];
    }
    cin >>k;
    for(int i=0;i<k;i++) {
        int u,v,m; cin >>u >>v >>m;
        u--,v--;
        adj[u].push_back({v,m});
    }
    int c; cin >>c;
    for(int i=0;i<c;i++) {
        int ci; cin >>ci; ci--;
        havePerak[ci] = 1;
    }
    cout <<dfs(s,havePerak[s]) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}