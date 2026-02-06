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

const int mxn=500,mxm=1000,mxa=1e9;
int n,m;
int a[mxn];
int id = 0;
vector<pii> fct[mxn];
pii uv[mxm];
vi fp;

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>uv[i].fi >>uv[i].se;
    }
    // fct
    rep(i,0,n) {
        for(int j=0;j<sz(fp)&&fp[j]*fp[j]<=a[i];j++) {
            while((a[i]%fp[j])==0) {
                fct[i].push_back({fp[j],id}); id++;
                a[i] /=fp[j];
            }
        }
        if(a[i]>1) {
            fct[i].push_back({a[i],id}); id++;
        }
    }
    Dinic dnc(id+2);
    int s=id, t=id+1;
    rep(i,0,n) {
        if(i%2) {
            for(auto [val,idi]: fct[i]) {
                dnc.addEdge(idi, t, 1);
            }
        } else {
            for(auto [val,idi]: fct[i]) {
                dnc.addEdge(s, idi, 1);
            }
        }
    }
    rep(i,0,m) {
        auto [u,v] = uv[i]; u--,v--;
        if(u%2) {
            swap(u,v);
        }
        for(auto [val,idi]: fct[u]) {
            for(auto [val2,idi2]: fct[v]) {
                if(val==val2) {
                    dnc.addEdge(idi,idi2, 1);
                }
            }
        }
    }
    ll ans = dnc.calc(s,t);
    cout <<ans <<"\n";
}

void init() {
    vector<bool> isComp(50000+1,0);
    for(int i=2;1ll*i*i<=mxa;i++) {
        if(!isComp[i]) {
            fp.push_back(i);
            for(int j=i*2;1ll*j*j<=mxa;j+=i) {
                isComp[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}