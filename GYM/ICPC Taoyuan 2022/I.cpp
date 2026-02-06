#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=5e4;
int m,n,t;
using pipi = tuple<int,int,int,int>;
pipi g[mxn],b[mxn];

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
    cin >>m >>n;
    int mxy = 0;
    rep(i,0,m) {
        int x1,y1,x2,y2; cin >>x1 >>y1 >>x2 >>y2;
        if(x1>x2 || (x1==x2 && y1>y2)) {
            swap(x1,x2);
            swap(y1,y2);
        }
        g[i] = {x1,y1,x2,y2};
        max_self(mxy, max(y1,y2));
    }
    rep(i,0,n) {
        int x1,y1,x2,y2; cin >>x1 >>y1 >>x2 >>y2;
        if(x1>x2 || (x1==x2 && y1>y2)) {
            swap(x1,x2);
            swap(y1,y2);
        }
        b[i] = {x1,y1,x2,y2};
        max_self(mxy, max(y1,y2));
    }
    vector<set<pipi>> sg(mxy+1);
    rep(i,0,m) {
        auto [x1,y1,x2,y2] = g[i];
        sg[y1].insert({x1,i,x2,y2});
    }
    Dinic dnc(n+m+2);
    int st = n+m, tg=st+1;
    rep(i,0,n) {
        auto [x1,y1,x2,y2] = b[i];
        // debug() <<imie(i) imie(x1) imie(y1) imie(x2) imie(y2);
        rep(yi,max(0,y1-2),y2) {
            auto it = sg[yi].lower_bound({x1-2,-1,-1,-1});
            while(it!=sg[yi].end()) {
                auto [p1,idg,p2,q2] = *it;
                int q1 = yi;
                if(p1>=x2) break;
                int bx1 = max(x1,p1), by1= max(y1,q1), bx2 = min(x2,p2), by2 = min(y2,q2);
                int ls = (p2-p1)*(q2-q1);
                // debug() <<imie(idg) imie(p1) imie(q1) imie(p2) imie(q2);
                // debug() <<imie(bx1) imie(bx2) imie(by1) imie(by2) imie(ls);
                if(max(bx2-bx1,0)*max(by2-by1,0)*2>=ls) {
                    dnc.addEdge(i,idg+n,1);
                }
                it++;
            }
        }
    }
    rep(i,0,n) {
        dnc.addEdge(st,i,1);
    }
    rep(i,0,m) {
        dnc.addEdge(i+n,tg,1);
    }
    cout <<dnc.calc(st,tg) <<"\n";
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