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

const int mxn=1e2;
int n,m;

const ll inff = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = sz(m);
	rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inff && m[k][j] != inff) {
			auto newDist = max(m[i][k] + m[k][j], -inff);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inff && m[k][j] != inff) m[i][j] = -inff;
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

void solve() {
    cin >>n >>m;
    // stok
    vector stok(n, vector<ll>(m));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>stok[i][j];
        }
    }
    // dist
    vector dist(n, vector<ll>(n));
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>dist[i][j];
            if(dist[i][j]==-1) {
                dist[i][j] = inff;
            }
        }
    }
    floydWarshall(dist);
    MCMF mcmf;
    mcmf.init(m+n+2);
    int st = m+n, tg=st+1;
    rep(i,0,m) {
        mcmf.ae(st, i, 1, 0);
        rep(j,0,n) {
            ll tmp = 0;
            rep(k,0,n) {
                tmp += stok[k][i]*dist[k][j];
            }
            mcmf.ae(i, j+m, 1, tmp);
        }
    }
    rep(j,0,n) {
        mcmf.ae(j+m, tg, 1, 0);
    }
    auto [fl,cs] = mcmf.calc(st, tg);
    cout <<cs <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}