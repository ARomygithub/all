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

#define tcT template<class T
tcT> using V = vector<T>; 

#define pb push_back

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)

struct MCMF { 
    using F = ll; using C = ll; // flow type, cost type
    struct Edge { int to; F flo, cap; C cost; };
    int N; V<C> p, dist; vi pre; V<Edge> eds; V<vi> adj;
    void init(int _N) { N = _N;
        p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N); }
    void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
        adj[u].pb(sz(eds)); eds.pb({v,0,cap,cost}); 
        adj[v].pb(sz(eds)); eds.pb({u,0,0,-cost});
    } // use asserts, don't try smth dumb
    bool path(int s, int t) { // find lowest cost path to send flow through
        const C inf = numeric_limits<C>::max(); rep(i,0,N) dist[i] = inf;
        using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
        todo.push({dist[s] = 0,s}); 
        while (sz(todo)) { // Dijkstra
            T x = todo.top(); todo.pop(); if (x.fi > dist[x.se]) continue;
            for(auto &e: adj[x.se]) { const Edge& E = eds[e]; // all weights should be non-negative
                if (0 < E.cap-E.flo && ckmin(dist[E.to],x.fi+E.cost+p[x.se]-p[E.to]))
                    pre[E.to] = e, todo.push({dist[E.to],E.to});
            }
        } // if costs are doubles, add some EPS so you 
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // return flow
    }
    pair<F,C> calc(int s, int t) { assert(s != t);
        rep(_,0,N) rep(e,0,sz(eds)) { const Edge& E = eds[e]; // Bellman-Ford
            if (E.cap) ckmin(p[E.to],p[eds[e^1].to]+E.cost); }
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { // p -> potentials for Dijkstra
            rep(i,0,N) p[i] += dist[i]; // don't matter for unreachable nodes
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = eds[pre[x]^1].to) {
                const Edge& E = eds[pre[x]]; ckmin(df,E.cap-E.flo); }
            totFlow += df; totCost += (p[t]-p[s])*df;
            for (int x = t; x != s; x = eds[pre[x]^1].to)
                eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
        } // get max flow you can send along path
        return {totFlow,totCost};
    }
};

const int mxn=2e3,mxc=1e5;
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    MCMF mcmf;
    mcmf.init(n*2+4);
    int st = n*2, tg = st+1;
    int sta = n*2+2, tga = sta+1;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        mcmf.ae(u*2+1, v*2, mxc, 0);
    }
    rep(i,0,n) {
        mcmf.ae(sta,i*2, a[i], 0);
        mcmf.ae(st, tga, a[i], 0);
        mcmf.ae(st, i*2, a[i], 1);
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