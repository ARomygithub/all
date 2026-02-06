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
    vector<multiset<int>> ed(n);
    rep(i,0,n) {
        rep(j,0,m) {
            int aij; cin >>aij;
            ed[i].insert(aij);
        }
    }
    vector<vi> ans(n);
    rep(i,0,m) {
        Dinic dinic(n*2+2);
        int s = 0, t=n*2+1;
        rep(j,1,n+1) {
            dinic.addEdge(s,j,1);
            dinic.addEdge(n+j,t,1);
        }
        rep(j,0,n) {
            for(auto edjk: ed[j]) {
                dinic.addEdge(j+1, edjk+n, 1);
            }
        }
        assert(dinic.calc(s,t)==n);
        rep(j,1,n+1) {
            for(auto edj: dinic.adj[j]) {
                int kn = edj.to;
                if(edj.flow()) {
                    ans[j-1].push_back(kn-n);
                    ed[j-1].erase(ed[j-1].find(kn-n));
                    break;
                }
            }
        }
    }
    cout <<"Yes\n";
    rep(i,0,n) {
        rep(j,0,sz(ans[i])) {
            cout <<ans[i][j] <<" \n"[j==sz(ans[i])-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}