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

// O(m^2 . sqrt(m) . lg m)
const int mxn=500;
int n;
int jm[mxn],x1[mxn],yi1[mxn],x2[mxn],y2[mxn];
vector<int> adj[mxn];

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

int dist(int a1, int b1, int a2, int b2) {
    return abs(a1-a2)+abs(b1-b2);
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>jm[i] >>x1[i] >>yi1[i] >>x2[i] >>y2[i];
    }
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            if(jm[i]>=jm[j]) continue;
            int tm = jm[i]+dist(x1[i],yi1[i],x2[i],y2[i])+dist(x2[i],y2[i],x1[j],yi1[j]);
            if(tm<jm[j]) {
                adj[i].push_back(j);
            }
        }
    }
    int ans = -1;
    int l=1,r=n;
    while(l<=r) {
        int mid = (l+r)/2;
        Dinic dnc(n*2+4);
        int s = n*2, t = s+1;
        int s1 = n*2+2, t1 = s1+1;
        rep(i,0,n) {
            for(int j : adj[i]) {
                dnc.addEdge(i*2+1,j*2,1);
            }
            dnc.addEdge(s1, i*2+1, 1);
            dnc.addEdge(i*2, t1, 1);
            dnc.addEdge(s, i*2, 1);
            dnc.addEdge(i*2+1, t, 1);
        }
        dnc.addEdge(t, s, mid);
        ll fl = dnc.calc(s1, t1);
        // cout <<mid <<" " <<fl <<endl;
        if(fl == n) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}