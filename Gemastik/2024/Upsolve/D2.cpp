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

const int mxn=1e5,mxq=1e5;
int n,m,q;
ll ans[mxq+1];

ll f(ll x) {
    return x*(x-1)/2;
}

struct RollbackUF {
    vi e; vector<pii> st;
    ll ans = 0; vector<ll> vans;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        int ct = time()-t;
        for (int i = time(); i --> t;) {
            e[st[i].first] = st[i].second;
            // ans = vans[i]; 
        }
        st.resize(t);
        int tans = sz(vans)-(ct/2);
        if(tans < sz(vans)) {
            ans = vans[tans];
        }
        vans.resize(tans);
    }
    bool join(int a, int b) {
        // assert(sz(st)==sz(vans));
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        vans.push_back(ans);
        ans -= f(-e[a]);
        ans -= f(-e[b]);
        ans += f(-(e[a]+e[b]));
        // debug() <<imie(a) imie(b);
        // debug() <<imie(-e[a]) imie(-e[b]) imie(-(e[a]+e[b]));
        // debug() <<imie(ans);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    vector<pii> ed;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    void add(int L, int R, pii uv) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            ed.push_back(uv);
            return;
        }
        else {
            push();
            l->add(L, R, uv), r->add(L, R, uv);
        }
    }
    void eval(RollbackUF& ruf) {
        int t_before = ruf.time();
        for(auto [u,v]: ed) {
            ruf.join(u,v);
        }
        if(hi==lo+1) {
            ans[lo] = ruf.ans; 
        } else {
            push();
            l->eval(ruf);
            r->eval(ruf);
        }
        ruf.rollback(t_before);
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
    }
};

// https://codeforces.com/blog/entry/104443

void solve() {
    cin >>n >>m >>q;
    RollbackUF ruf(n);
    vector ts(m, vi());
    vector<pii> ed(m);
    rep(i,0,m) {
        int u,v,z; cin >>u >>v >>z; u--,v--;
        if(z>0) {
            // debug() <<imie(u) imie(v) imie(z);
            ts[i].push_back(0);
        } 
        ed[i] = {u,v};
    }
    rep(i,0,q) {
        char c; int id; cin >>c >>id; id--;
        if(sz(ts[id])%2) {
            // assert(c=='G');
            if(c=='A') {
                continue;
            }
        } else {
            // assert(c=='A');
            if(c=='G') {
                continue;
            }
        }
        ts[id].push_back(i+1);
    }
    Node st(0,q+1);
    // debug() <<imie(ts);
    rep(i,0,m) {
        for(auto j=0;j<sz(ts[i]);j+=2) {
            // cout <<"-" <<endl;
            int le = ts[i][j];
            int ri = (j+1<sz(ts[i])?ts[i][j+1]:q+1);
            // debug() <<imie(le) imie(ri) imie(ed[i]);
            st.add(le,ri, ed[i]);
        }
    }
    // cout <<"tes" <<endl;
    st.eval(ruf);
    rep(i,1,q+1) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}