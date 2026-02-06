#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define dbg(x) cerr <<#x <<": " <<x <<endl

// Dinic
struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
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
        for(int& i = ptr[v]; i<sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if(lvl[e.to] == lvl[v]+1) {
                if(ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
            }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while(qi < qe && !lvl[t]) {
                int v = q[qi++];
                for(Edge e: adj[v]) 
                    if(!lvl[e.to] && e.c >> (30-L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v]+1;
            } 
            while(ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while( lvl[t]);
        return flow;
    }

};

const int mxn = 500;
int n,m;
string a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector adj(m, vi());
    vector b(m, vector<bool>(m,0));
    Dinic dnc(m*2+2);
    int s = m*2, t = s+1;
    rep(i,0,m) {
        dnc.addEdge(s, i, 1);
        dnc.addEdge(i+m, t, 1);
    }
    rep(i,0,m) {
        rep(j,i+1,m) {
            bool ki = 0, kj = 0;
            rep(k,0,n) {
                if(a[k][i]!=a[k][j]) {
                    if(a[k][i]=='1') {
                        ki = 1;
                    } else {
                        kj = 1;
                    }
                }
            }
            swap(ki,kj); // reverse i,j
            if(ki && kj) {
                continue;
            } else if(ki) {
                b[j][i] = 1;
                dnc.addEdge(j, i+m, 1);
            } else if(kj) {
                b[i][j] = 1;
                dnc.addEdge(i, j+m, 1);
            } else {
                b[i][j] = 1;
                b[j][i] = 1;
                dnc.addEdge(i, j+m,1);
                // dnc.addEdge(j,i+m,1);
            }
        }
    }
    ll res = dnc.calc(s,t);
    // cout <<m-res <<"\n";
    int k = m - res;
    // dbg(k);
    rep(i,0,m) {
        for(auto& e: dnc.adj[i]) {
            if(e.flow()) {
                int to = e.to;
                adj[i].push_back(to-m);
                adj[to-m].push_back(i);
                // dbg(i);
                // dbg(to-m);
                break;
            }
        }
    }
    vector<vi> gr;
    vector<bool> vis(m,0);
    set<int> st;
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        st.insert(u);
        vis[u] = 1;
        for(int v: adj[u]) {
            if(v==p) continue;
            dfs(v,u);
        }
    };
    rep(i,0,m) {
        if(!vis[i]) {
            dfs(i,-1);
            vi gri;
            map<int,int> ct;
            for(auto& si: st) {
                for(auto& sj: st) {
                    if(b[sj][si]) {
                        ct[si]++;
                    }
                }
                gri.push_back(si);
            }
            sort(all(gri), [&](int si, int sj) -> bool {
                return ct[si]<ct[sj];
            });
            gr.push_back(gri);
            st.clear();
        }
    }
    assert(sz(gr)==k);
    vi lead(m,-1), val(m,-1);
    rep(i,0,k) {
        rep(j,0,sz(gr[i])) {
            int u = gr[i][j];
            lead[u] = i;
            val[u] = j+2;
        }
    }
    vector vn(n, vi(k,1));
    rep(i,0,n) {
        rep(j,0,k) {
            rep(jj,0,sz(gr[j])) {
                int u = gr[j][jj];
                if(a[i][u]=='1') {
                    vn[i][j] = jj+2;
                } else {
                    break;
                }
            }
        }
    }
    cout <<k <<"\n";
    rep(i,0,m) {
        cout <<lead[i]+1 <<" \n"[i==m-1];
    }
    rep(i,0,m) {
        cout <<val[i] <<" \n"[i==m-1];
    }
    rep(i,0,n) {
        rep(j,0,k) {
            cout <<vn[i][j] <<" \n"[j==k-1];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}