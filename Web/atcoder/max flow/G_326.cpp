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

const int mxn=50;
int n,m;
int c[mxn],a[mxn], l[mxn][mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>c[i];
    }
    rep(i,0,m) {
        cin >>a[i];
    }
    const int inf = 1001001001;
    int ln = n*4;
    int sv = ln+m, tv = sv+1;
    Dinic dinic(tv+1);
    rep(i,0,n) {
        int v = i*4;
        rep(j,0,3) {
            dinic.addEdge(v+j+1, v+j, inf);
        }
        rep(j,0,4) {
            int l = v+j, r = (j==3)?tv:v+j+1;
            dinic.addEdge(l,r,c[i]*(j+1));
        }
    }
    int ans = 0;
    rep(j,0,m) {
        ans += a[j];
        dinic.addEdge(sv, ln+j, a[j]);
        rep(i,0,n) {
            cin >>l[j][i];
            if(l[j][i]==1) continue;
            dinic.addEdge(ln+j,i*4+l[j][i]-2,inf);
        }
    }
    ans -= dinic.calc(sv, tv);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}