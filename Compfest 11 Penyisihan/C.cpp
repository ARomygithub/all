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

const int mxn=2e5;
int n,q;
vector<vi> adj;

const ll inf = 0,setc=1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = setc, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val = x*(hi-lo), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != setc) mset += x;
            else madd += x;
            val += x*(hi-lo);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != setc)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = setc;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

template <bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node *tree;
    HLD(vector<vi> adj_)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
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
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, int val) {
        process(u, v, [&](int l, int r) { tree->set(l, r, val); });
    }
    ll queryPath(int u, int v) { // Modify depending on problem
        ll res = 0;
        process(u, v, [&](int l, int r) {
                res += tree->query(l, r);
        });
        return res;
    }
    int querySubtree(int v) { // modifySubtree is similar
        return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};

void solve() {
    cin >>n >>q;
    adj.resize(n);
    map<pii,int> mp;
    rep(i,1,n) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        mp[{u,v}] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD<true> hld(adj);
    for(auto [uv,w]: mp) {
        auto [u,v] = uv;
        hld.modifyPath(u,v,w);
    }
    while(q--) {
        int u,v; cin >>u >>v; u--,v--;
        ll res = hld.queryPath(u,v);
        cout <<res <<"\n";
        hld.modifyPath(u,v,0ll);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}