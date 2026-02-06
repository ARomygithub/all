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

const int mxn=1e5;
int n,q;
int T = 0;
vector<int> ti(mxn),d(mxn,0),en(mxn),par;
vector<int> adj[mxn];

void dfs(int u, int p=-1) {
    ti[u] = T++;
    en[u] = ti[u];
    for(int v: adj[u]) {
        if(v==p) continue;
        d[v] = d[u]+1;
        par[v] = u;
        dfs(v,u);
        max_self(en[u], en[v]);
    }
}

vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

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
        if (L <= lo && hi <= R) mset = x, madd = 0, val = x*(hi-lo);
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

void solve() {
    cin >>n >>q;
    vector<int> a(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par.resize(n,0);
    dfs(0,-1);
    auto tbl = treeJump(par);
    int r = 0;
    Node st(0,n);
    rep(i,0,n) {
        st.set(ti[i], ti[i]+1, a[i]);
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int v; cin >>v; v--;
            r = v;
        } else if(qt==2) {
            int u,v; cin >>u >>v; u--,v--;
            int w; cin >>w;
            int lu = lca(tbl, d, u,r), lv =lca(tbl, d, v,r);
            if(lu!=r && lv!=r) {
                int x = ti[lu]>=ti[lv]?lu:lv; // down sekali
                assert(d[x]>=d[lu] && d[x]>=d[lv]);
                // cout <<"x before " <<x <<endl;
                x = jmp(tbl, r, d[r]-d[x]-1);
                // cout <<"x after " <<x <<endl;
                st.add(0, ti[x], w);
                st.add(en[x]+1, n, w);
            } else {

                if(lu==r && lv==r) {
                    int luv = lca(tbl, d, u,v); // case luv=r
                    if(luv==r) {
                        st.add(0, n, w);
                    } else {
                        st.add(ti[luv], en[luv]+1, w);
                    }
                } else {
                    st.add(0, n, w);
                }
            }
        } else {
            int v; cin >>v; v--;
            int lv = lca(tbl, d, v,r);
            ll qry;
            if(lv==v && v!=r) {
                // cout <<"v before " <<v <<endl;
                v = jmp(tbl, r, d[r]-d[v]-1);
                // cout <<"v after " <<v <<endl;
                qry = st.query(0,n) - st.query(ti[v], en[v]+1);
                assert(qry == st.query(0, ti[v])+st.query(en[v]+1,n));
            } else if(v==r) {
                qry = st.query(0,n);
            } else {
                qry = st.query(ti[v], en[v]+1);
            }
            cout <<qry <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}