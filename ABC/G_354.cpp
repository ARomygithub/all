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

const int mxn=100;
int n, a[mxn];
string s[mxn];

bool isSubstr(int i, int j) {
    rep(jj,0,sz(s[j])-sz(s[i])+1) {
        bool ok = 1;
        rep(ii,0,sz(s[i])) {
            ok = ok && s[i][ii]==s[j][jj+ii];
            if(!ok) break;
        }
        if(ok) return true;
    }
    return false;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    Dinic dnc(n*2+2);
    int st=n*2, tg=st+1;
    rep(i,0,n) {
        dnc.addEdge(st,i, a[i]);
        dnc.addEdge(i+n,tg, a[i]);
    }
    const ll inf = 1e11; 
    rep(i,0,n) {
        rep(j,0,n) {
            if(s[i]==s[j]) {
                if(i<j) {
                    dnc.addEdge(i, j+n, inf);
                }
            } else if(isSubstr(i,j)) {
                dnc.addEdge(i,j+n, inf);
            }
        }
    }
    ll fl = dnc.calc(st, tg);
    ll sm = 0;
    rep(i,0,n) {
        sm += a[i];
    }
    cout <<sm-fl <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}