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
int n,q;
vector<pii> adj[mxn];
vi par, c,d;

struct UF {
    vi e, top;
    UF(int n) : e(n, -1) {
        top.resize(n);
        iota(top.begin(),top.end(),0);
    }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        if(d[top[b]]<d[top[a]]) {
            top[a] = top[b];
        }
        return true;
    }
};

vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

void dfs(int u, int p=-1) {
    for(auto [w,v]: adj[u]) {
        if(v==p) continue;
        d[v] = d[u]+1;
        par[v] = u;
        c[v] = w;
        dfs(v,u);
    }
}

void solve() {
    cin >>n >>q;
    par.resize(n,0);
    c.resize(n,-1);
    d.resize(n,0);
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    dfs(0,-1);
    auto tbl = treeJump(par);
    UF uf(n);
    while(q--) {
        int u,v; cin >>u >>v; u--,v--;
        int lc = lca(tbl, d, u, v);
        ll res = 0;
        while(u!=lc) {
            u = uf.top[uf.find(u)];
            if(d[u]<=d[lc]) break;
            res += c[u];
            uf.join(u, par[u]);
            u = par[u];
        }
        while(v!=lc) {
            v = uf.top[uf.find(v)];
            if(d[v]<=d[lc]) break;
            res += c[v];
            uf.join(v, par[v]);
            v = par[v];
        }
        cout <<res <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}