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
    using F = ll; using C = ll; // flow type, cost type
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
    pair<F,C> calc(int s, int t, ll flowLimit) { assert(s != t);
        F0R(_,N) F0R(e,sz(eds)) { const Edge& E = eds[e]; // Bellman-Ford
            if (E.cap) ckmin(p[E.to],p[eds[e^1].to]+E.cost); }
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { // p -> potentials for Dijkstra
            F0R(i,N) p[i] += dist[i]; // don't matter for unreachable nodes
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = eds[pre[x]^1].to) {
                const Edge& E = eds[pre[x]]; ckmin(df,E.cap-E.flo); }
            if(totFlow+df>flowLimit) {
                F tmp = flowLimit-totFlow;
                totFlow += tmp; totCost += (p[t]-p[s])*tmp;
                break; 
            }
            totFlow += df; totCost += (p[t]-p[s])*df;
            for (int x = t; x != s; x = eds[pre[x]^1].to)
                eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
        } // get max flow you can send along path
        return {totFlow,totCost};
    }
};

const int mxn=1e3;
const ll big=15e8;
int n,m,k;
int a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n >>m >>k;
    vi mnr(n,big),mnc(m,big);
    rep(i,0,k) {
        cin >>a[i] >>b[i] >>c[i]; a[i]--,b[i]--;
        min_self(mnr[a[i]],c[i]);
        min_self(mnc[b[i]],c[i]);
    }
    MCMF mcmf;
    mcmf.init(n+m+2);
    int st = n+m, tg=st+1;
    ll ans = 0;
    rep(i,0,k) {
        mcmf.ae(a[i],b[i]+n,1,big+c[i]-mnr[a[i]]-mnc[b[i]]);
    }
    rep(i,0,n) {
        ans += mnr[i];
        mcmf.ae(st,i,1,0);
    }
    rep(i,0,m) {
        ans += mnc[i];
        mcmf.ae(i+n,tg,1,0);
    }
    mcmf.ae(st,tg,min(n,m),big);
    auto [fl,cs] = mcmf.calc(st,tg,min(n,m));
    // cout <<ans <<endl;
    // cout <<fl <<" " <<cs <<endl;
    ans += cs - big*fl;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}