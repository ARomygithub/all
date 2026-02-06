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

const int mxn=3e5;
int n,m,t;
int d[mxn];

struct UF {
    vi e;
    vector<ll> ans;
    vector<vi> adj;
    UF(int n) : e(n, -1), ans(n,0), adj(n) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b, int w) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        ans[a] += 1ll*(-e[b])*w;
        ans[b] += 1ll*(-e[a])*w - ans[a];
        e[a] += e[b]; e[b] = a;
        return true;
    }
    void dfs(int u, int p) {
        for(int v: adj[u]) {
            if(v==p) continue;
            ans[v] += ans[u];
            dfs(v,u);
        }
    }
    void acc() {
        int u = find(0);
        dfs(u,-1);
    }
};

using ipii = pair<int,pii>;
void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>d[i];
    }
    vector<ipii> ed;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        ed.push_back({max(d[u],d[v]),{u,v}});
    }
    sort(all(ed));
    UF uf(n);
    rep(i,0,m) {
        auto [du, uv] = ed[i];
        auto [u,v] = uv;
        uf.join(u,v,du);
    }
    uf.acc();
    rep(i,0,n) {
        cout <<uf.ans[i]+d[i] <<" \n"[i==n-1];
    }
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