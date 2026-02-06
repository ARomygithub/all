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

const int mxn=1e5;
int n,m;

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
    vector<pii> ed(m);
    vi d(m);
    rep(i,0,m) {
        cin >>ed[i].fi >>ed[i].se >>d[i];
        ed[i].fi--; ed[i].se--;
    }
    int ans = -1;
    const int mxb = 5e6;
    int l = 0, r = mxb;
    while(l<=r) {
        int mid = (l+r)/2;
        Dinic dnc(n+m+2);
        int st = n+m, tg=st+1;
        rep(i,0,n) {
            dnc.addEdge(st,i, mid);
        }
        rep(i,0,m) {
            dnc.addEdge(i+n,tg, d[i]);
        }
        rep(i,0,m) {
            auto [u,v] = ed[i];
            dnc.addEdge(u,i+n, d[i]);
            dnc.addEdge(v,i+n, d[i]);
        }
        ll fl = dnc.calc(st, tg);
        if(fl==mid*n) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    int ds = 0;
    rep(i,0,m) {
        ds += d[i];
    }
    ds -= ans*n;
    cout <<ds <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}