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

const int mxn=1e5,mxq=2e5;
int n,m,q,t;
vi f;
pii ed[mxq];

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

using ipii = pair<int,pii>;

// bef: st, blm connect. af: st.
void slv(RollbackUF& ruf, int st, int en, vector<ipii>& vq) {
    // debug() <<imie(st) imie(en);
    // debug() <<imie(vq);
    if(en-st<=1) return;
    int mid = (st+en)/2;
    int t0 = ruf.time();
    vector<ipii> vq0, vq1;
    rep(i,st,mid) {
        ruf.join(ed[i].fi,ed[i].se);
    }
    for(auto& [id,lr]: vq) {
        auto& [l,r] = lr;
        if(ruf.find(l)==ruf.find(r)) {
            vq0.push_back({id,lr});
            f[id] = mid;
        } else {
            vq1.push_back({id,lr});
        }
    }
    if(sz(vq0)>0 && mid>st) {
        ruf.rollback(t0);
        slv(ruf, st, mid, vq0);
        rep(i,st,mid) {
            ruf.join(ed[i].fi,ed[i].se);
        }        
    }
    if(sz(vq1)>0 && mid<en) {
        slv(ruf,mid,en,vq1);
    }
    ruf.rollback(t0);
}

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

void solve() {
    cin >>n >>m >>q;
    rep(i,0,m) {
        cin >>ed[i].fi >>ed[i].se; ed[i].fi--,ed[i].se--;
    }
    vector<ipii> vq(n-1);
    f = vi(n-1,m);
    rep(i,0,n-1) {
        vq[i].fi = i;
        vq[i].se = {i,i+1};
    }
    RollbackUF ruf(n);
    slv(ruf, 0, m, vq);
    RMQ<int> rmq(f);
    rep(i,0,q) {
        int l,r; cin >>l >>r; l--,r--;
        int ans = -1;
        if(l==r) {
            ans = 0;
        } else {
            ans = rmq.query(l,r);
        }
        cout <<ans <<" \n"[i==q-1];
    }
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