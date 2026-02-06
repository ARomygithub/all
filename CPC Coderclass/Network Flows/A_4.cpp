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

const int mxn=5000;
int n,k;
string s[mxn];

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
    cin >>n >>k;
    rep(i,0,n) {
        cin >>s[i];
    }
    map<string,int> mp,ms;
    int id = 0;
    vector<vi> adj;
    rep(i,0,n) {
        string pref="";
        string suf = "";
        rep(j,0,k) {
            pref += s[i][j];
        }
        rep(j,0,k) {
            suf += s[i][sz(s[i])-k+j];
        }
        if(!mp.count(pref)) {
            mp[pref] = id; id++;
            adj.push_back(vi());
        }
        int prefid = mp[pref];
        if(!ms.count(suf)) {
            ms[suf] = id; id++;
            adj.push_back(vi());
        }
        int sufid = ms[suf];
        adj[prefid].push_back(sufid);
    }
    Dinic dnc(id+2);
    int st = id, tg = st+1;
    for(auto [pref, idp]: mp) {
        dnc.addEdge(st, idp, 1);
        for(auto ids : adj[idp]) {
            dnc.addEdge(idp, ids, 1);
        }
    }
    for(auto [suf, ids]: ms) {
        dnc.addEdge(ids, tg, 1);
    }
    ll fl = dnc.calc(st, tg);
    set<int> cand;
    for(auto [pref, idp]: mp) {
        if(!dnc.leftOfMinCut(idp)) {
            cand.insert(idp);
        }
    }
    for(auto [suf, ids]: ms) {
        if(dnc.leftOfMinCut(ids)) {
            cand.insert(ids);
        }
    }
    map<int,vi> ans;
    rep(i,0,n) {
        string pref="", suf="";
        rep(j,0,k) {
            pref += s[i][j];
        }
        rep(j,0,k) {
            suf += s[i][sz(s[i])-k+j];
        }
        int idp = mp[pref], ids=ms[suf];
        if(cand.count(idp)) {
            ans[idp].push_back(i+1);
        } else {
            ans[ids].push_back(i+1);
        }
    }
    assert(fl==sz(ans));
    cout <<sz(ans) <<"\n";
    for(auto [idps, v]: ans) {
        cout <<sz(v) <<" ";
        rep(i,0,sz(v)) {
            cout <<v[i] <<" \n"[i==sz(v)-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}