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
vector<int> adj[mxn];
int sub[mxn];

void dfs1(int u, int p=-1) {
    sub[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
        sub[u] += sub[v];
    }
}

int dfs2(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        if(sub[v]>(n/2)) {
            return dfs2(v,u);
        }
    }
    return u;
}

bool dfs3(int u, int p=-1) {
    bool ret = 1;
    set<pii> s;
    int su = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        s.insert({sub[v],v});
    }
    for(auto [sv,v]: s) {
        ret &= dfs3(v,u);
        ret &= su>=sv;
        if(!ret) return ret;
        su += sv;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0);
    int r = dfs2(0);
    dfs1(r);
    bool ok = dfs3(r);
    if(ok) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}