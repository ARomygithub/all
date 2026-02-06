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
int n,t;
vector<pii> adj[mxn*2];
int sub[mxn*2];
ll g=0,b=0;

void dfs(int u, int p=-1) {
    sub[u] = 1;
    for(auto [w,v]: adj[u]) {
        if(p==v) continue;
        dfs(v,u);
        sub[u] +=sub[v];
    }
}

int findRoot(int u, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(p==v) continue;
        if(sub[v]>n) {
            return findRoot(v,u);
        }
    }
    return u;
}

void dfsans(int u, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(p==v) continue;
        if(sub[v]%2) {
            g +=1ll*w;
        }
        b +=1ll*w*sub[v];
        // cout <<w <<" " <<sub[v] <<"\n";
        dfsans(v,u);
    }
}

void solve() {
    cin >>n;
    rep(i,0,n*2 - 1) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    dfs(0);
    int root = findRoot(0);
    // cout <<root <<"\n";
    dfs(root);
    g = 0, b=0;
    dfsans(root);
    cout <<g <<" " <<b <<"\n";
    rep(i,0,n*2) {
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