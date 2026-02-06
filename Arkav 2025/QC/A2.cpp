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

const int mxn=1e5;
int n,k,r;

const ll inf = 1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = -inf, madd = 0, val = inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != -inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != -inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

template <bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    vector<Node*> tree;
    HLD(vector<vi> adj_, int rot, int ki)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N,rot),pos(N) { 
            dfsSz(rot); dfsHld(rot); 
            rep(i,0,ki) {
                tree.push_back(new Node(0,N));
            }  
        }
    void dfsSz(int v) {
        if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
        for (int& u : adj[v]) {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template <class B> void process(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
            // cout <<"cek" <<endl;
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, ll val, int ki) {
        process(u, v, [&](int l, int r) { 
            tree[ki]->set(l, r, val); });
    }
    ll queryPath(int u, int v, int ki) { // Modify depending on problem
        ll res = 1e18;
        process(u, v, [&](int l, int r) {
                res = min(res, tree[ki]->query(l, r));
        });
        return res;
    }
};

void solve() {
    cin >>n >>k >>r; r--;
    vector<vi> adj(n);
    vector adj2(k, vector(n, vector<pii>()));
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        rep(j,0,k) {
            int ci; cin >>ci;
            adj2[j][u].push_back({v,ci});
            adj2[j][v].push_back({u,ci});
        }
    }
    vector s(k, vector<ll>(n));
    rep(i,0,k) {
        rep(j,0,n) {
            cin >>s[i][j];
        }
    }
    HLD<false> hld(adj, r, k);
    // cout <<"tes" <<endl;
    vector pot(n, vector<ll>(k,0));
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        rep(i,0,sz(adj2[0][u])) {
            if(adj2[0][u][i].fi==p) continue;
            int v = adj2[0][u][i].fi;
            rep(j,0,k) {
                int cs = adj2[j][u][i].se;
                pot[v][j] = pot[u][j] + cs;
            }
            dfs(v,u);
        } 
    };
    dfs(r,-1);
    // debug() <<imie(hld.par);
    // debug() <<imie(hld.rt);
    vector<ll> ans(n,1e18);
    rep(i,0,n) {
        vector<ll> dpi(k,1e18);
        rep(j,0,k) {
            dpi[j] = pot[i][j];
            ll cur = hld.queryPath(i,r, j);
            // if(i==3 && j==1) {
            //     debug() <<imie(j) imie(cur) imie(dpi[j]) imie(pot[i][j]);
            // }
            cur += pot[i][j];
            // assert(cur>=0);
            min_self(dpi[j], cur);
        }
        ll cur = 1e18;
        rep(j,0,k) {
            min_self(ans[i], dpi[j]);
            min_self(cur, dpi[j]+s[j][i]);
        }
        rep(j,0,k) {
            hld.modifyPath(i,i, cur-pot[i][j], j);
            // debug() <<imie(i) imie(j) imie(cur-pot[i][j]);
        }
        // cout <<cur <<endl;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}