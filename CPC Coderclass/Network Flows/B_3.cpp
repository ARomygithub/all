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

const int mxn=5e2,mxm=1e2;
int m,k;
string t[mxm], s0;
int p[mxm];

#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

struct MCMF { 
    using F = double; using C = double; // flow type, cost type
    struct Edge { int to; F flo, cap; C cost; };
    int N; V<C> p, dist; vi pre; V<Edge> eds; V<vi> adj;
    void init(int _N) { N = _N;
        p.rsz(N), dist.rsz(N), pre.rsz(N), adj.rsz(N); }
    void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
        adj[u].pb(sz(eds)); eds.pb({v,0,cap,cost}); 
        adj[v].pb(sz(eds)); eds.pb({u,0,0,-cost});
    } // use asserts, don't try smth dumb
    bool path(int s, int t) { // find lowest cost path to send flow through
        const C inf = numeric_limits<C>::max(); F0R(i,N) dist[i] = inf;
        using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
        todo.push({dist[s] = 0,s}); 
        while (sz(todo)) { // Dijkstra
            T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
            each(e,adj[x.s]) { const Edge& E = eds[e]; // all weights should be non-negative
                if (0 < E.cap-E.flo && ckmin(dist[E.to],x.f+E.cost+p[x.s]-p[E.to]))
                    pre[E.to] = e, todo.push({dist[E.to],E.to});
            }
        } // if costs are doubles, add some EPS so you 
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // return flow
    }
    pair<F,C> calc(int s, int t) { assert(s != t);
        F0R(_,N) F0R(e,sz(eds)) { const Edge& E = eds[e]; // Bellman-Ford
            if (E.cap) ckmin(p[E.to],p[eds[e^1].to]+E.cost); }
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { // p -> potentials for Dijkstra
            F0R(i,N) p[i] += dist[i]; // don't matter for unreachable nodes
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

vi pi(const string& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

vi match(const string& s, const string& pat) {
    vi p = pi(pat + '\0' + s), res;
    rep(i,sz(p)-sz(s),sz(p))
        if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
    return res;
}

void solve() {
    cin >>s0;
    cin >>m;
    rep(i,0,m) {
        cin >>t[i] >>p[i];
    }
    cin >>k;
    MCMF mcmf;
    mcmf.init(sz(s0)+3);
    int st = sz(s0)+1, tg = st+1;
    rep(i,0,m) {
        auto matching = match(s0, t[i]);
        for(auto idx: matching) {
            mcmf.ae(idx, idx+sz(t[i]), 1, -p[i]);
        }
    }
    mcmf.ae(st, 0, k, 0);
    mcmf.ae(sz(s0), tg, k, 0);
    rep(i,0,sz(s0)) {
        mcmf.ae(i, i+1, k, 0);
    }
    auto [fl, cost] = mcmf.calc(st, tg);
    cout <<-cost <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}