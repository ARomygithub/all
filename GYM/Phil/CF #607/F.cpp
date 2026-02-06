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
typedef pair<int,ll> pil;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e3;
int n,m,t;
ll wb[mxn];
vector<int> adj[mxn];
vector<pil> dp[mxn];

void dfsans(int u, int p=-1) {
    dp[u].resize(1);
    dp[u][0] = {0, wb[u]};
    for(int v: adj[u]) {
        if(v == p) continue;
        dfsans(v, u);
        vector<pil> dp_new(sz(dp[u])+sz(dp[v]), {0, (ll)(-1e18)});
        rep(i, 0, sz(dp[u])) {
            rep(j, 0, sz(dp[v])) {
                pil temp1 = {dp[u][i].fi+dp[v][j].fi+(dp[v][j].se>0), dp[u][i].se};
                max_self(dp_new[i+j+1], temp1);
                pil temp2 = {dp[u][i].fi+dp[v][j].fi, dp[u][i].se + dp[v][j].se};
                max_self(dp_new[i+j], temp2);
            }
        }
        dp[u].swap(dp_new);
    }
    // cout <<u <<"\n";
    // rep(i,0,sz(dp[u])) {
    //     cout <<i+1 <<" " <<dp[u][i].fi <<" " <<dp[u][i].se <<"\n";
    // }
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>wb[i];
    }
    rep(i,0,n) {
        ll w; cin >>w;
        wb[i] = w - wb[i];
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsans(0);
    cout <<dp[0][m-1].fi + (dp[0][m-1].se>0) <<"\n";
    rep(i,0,n) {
        adj[i].clear();
        dp[i].clear();
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