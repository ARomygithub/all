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

const int mxn=5e5;
int n;

const ll inf = 0, setc=4e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = setc, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            val = x*(hi-lo);
            madd = 0;
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != setc) {
                mset += x;
            } else {
                madd += x;
            }
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
    void modifyPath(int u, int v, ll val) {
        process(u, v, [&](int l, int r) { tree->add(l, r, val); });
    }
    ll queryPath(int u, int v) { // Modify depending on problem
        ll res = 0;
        process(u, v, [&](int l, int r) {
                res += tree->query(l, r);
        });
        return res;
    }
};

using tup = tuple<string, int , int>;
void solve() {
    cin >>n;
    vector<vi> adj;
    adj.push_back(vi());
    int id = 1, id2=1;
    vector<tup> qry;
    rep(i,0,n) {
        string s; int t, x; cin >>s >>t;
        x = 0;
        if(s[0]=='S') {
            cin >>x;
            adj.push_back(vi());
            adj[t].push_back(id);
            adj[id].push_back(t);
            id++;
        } else if(s[sz(s)-1]=='k') {
            cin >>x;
        }
        // debug() <<imie(s) imie(t) imie(x);
        qry.push_back({s,t,x});
    }
    // debug() <<imie(id);
    HLD<false> hld(adj);
    vector<ll> val(id,0);
    vector<bool> elim(id,0);
    // debug() <<"init hld";
    rep(i,0,n) {
        auto [s, t, x] = qry[i];
        if(s[0]=='S') {
            ll qr = hld.queryPath(0,t);
            x -= qr;
            val[id2] = x;
            id2++;
        } else if(s[sz(s)-1]=='k') {
            hld.modifyPath(t, t, x);
        } else if(s[sz(s)-1]=='s') {
            elim[t] = 1;
        }
    }
    // debug() <<imie(val);
    vector<pll> ans;
    function<void(int,int, ll)> dfs;
    dfs = [&](int u, int p, ll add) -> void {
        if(elim[u]) return;
        val[u] += add;
        ans.push_back({u,val[u]});
        for(int v: adj[u]) {
            if(v==p) continue;
            // val[v] += val[u];
            dfs(v,u, add + hld.queryPath(v,v));
        }
    };
    // debug() <<"tes";
    dfs(0,-1,hld.queryPath(0,0));
    sort(all(ans));
    rep(i,0,sz(ans)) {
        cout <<ans[i].se <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}