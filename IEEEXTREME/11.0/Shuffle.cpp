#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
#define rep(i,from,to) for(int i = from; i < (to);i++)
typedef vector<int> vi; 

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=200;
int n;

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() {return max(oc-c, 0LL);}
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n): lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a])-1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if(v == t || !f) return f;
        for(int& i = ptr[v];i<sz(adj[v]);i++) {
            Edge& e = adj[v][i];
            if(lvl[e.to] == lvl[v]+1)
                if(ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -=p, adj[e.to][e.rev].c +=p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe=lvl[s] = 1;
            while(qi<qe && !lvl[t]) {
                int v = q[qi++];
                for(Edge e : adj[v]) {
                    if(!lvl[e.to] && e.c >> (30-L)) {
                        q[qe++] = e.to, lvl[e.to] = lvl[v]+1;
                    }
                }
            }
            while(ll p = dfs(s,t, LLONG_MAX)) flow += p;
        } while(lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) {return lvl[a] != 0;}
};

void solve() {
    string s;
    getline(cin, s);
    stringstream ss0(s);
    ss0 >>n;
    Dinic dinic(2*n+2);
    for(int i=0;i<n;i++) {
        getline(cin, s);
        stringstream ssi(s);
        int v;
        set<int> sti;
        while(ssi >> v) {
            sti.insert(v);
        }
        for(v=0;v<n;v++) {
            if(v==i) continue;
            if(sti.find(v)==sti.end()) {
                dinic.addEdge(2*i,2*v+1,1);
            }
        }
    }
    for(int i=0;i<n;i++) {
        dinic.addEdge(2*n,2*i,1);
        dinic.addEdge(2*i+1,2*n+1,1);
    }
    ll flow = dinic.calc(2*n,2*n+1);
    cout <<n-flow <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}