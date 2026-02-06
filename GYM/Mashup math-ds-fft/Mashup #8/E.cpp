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
int n,m,k;
int c[mxn];

struct UF {
    vi e, clri;
    vector<bool> valid;
    vector<map<int,int>> mp;
    UF(int n, int k) : e(n, -1), valid(k,1), clri(n,-1), mp(n) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    cin >>n >>m >>k;
    // valid
    // pake dsu jg tapi ngecek gada edge R-R
    // set pii forbid
    // join 2 dsu. Dsu simpen map<int,int> mp (relasi R-R,R-B,.. apa aja yg udh antara this dan mp[k])
    /*
    BB = 0
    BR = 1
    RB = 2
    RR = 3
    cek superset dari 3 dan 12
    */
    UF uf(n,k);
    vector nk(k, vi());
    rep(i,0,n) {
        cin >>c[i]; c[i]--;
        nk[c[i]].push_back(i);
    }    
    vector<pii> ed;
    vector edk(n, vi());
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(c[u]==c[v]) {
            edk[u].push_back(v);
            edk[v].push_back(u);
        } else {
            ed.push_back({u,v});
        }
    }
    function<void(int,int)> dfs;
    dfs = [&](int u, int cl) -> void {
        uf.clri[u] = cl;
        for(auto v: edk[u]) {
            if(uf.clri[v]==-1) {
                uf.join(u,v);
                dfs(v, 1- cl);
                if(!uf.valid[c[u]]) return;
            } else {
                // debug() <<imie(u) imie(v);
                // debug() <<imie(uf.clri[u]) imie(uf.clri[v]);
                if(uf.clri[u]==uf.clri[v]) {
                    uf.valid[c[u]] = 0;
                    return;
                }
            }
        }
    };
    rep(i,0,k) {
        for(auto u : nk[i]) {
            if(uf.clri[u]==-1) {
                dfs(u, 0);
            }
        }
    }
    ll ans = 0;
    {
        ll ct = 0;
        rep(i,0,k) {
            if(uf.valid[i]) {
                ct++;
            }
        }
        ans = ct*(ct-1)/2;
        debug() <<imie(ct);
    } 
    for(auto [u,v]: ed) {
        int cu = c[u], cv = c[v];
        if(uf.valid[cu] && uf.valid[cv]) {
            int valu = 1<<(uf.clri[u]*2 + uf.clri[v]);
            int valv = 1<<(uf.clri[v]*2 + uf.clri[u]);
            int lu = uf.find(u), lv = uf.find(v);
            uf.mp[lu][lv] = uf.mp[lu][lv] | valu;
            uf.mp[lv][lu] = uf.mp[lv][lu] | valv;
        }
    }
    set<pii> forbid;
    set<int> ld;
    rep(i,0,n) {
        ld.insert(uf.find(i));
    }
    for(auto lu: ld) {
        for(auto [lv, val]: uf.mp[lu]) {
            int cu = c[lu], cv=c[lv];
            if((val&3)==3 || (val&12)==12) {
                if(cu>cv) swap(cu,cv);
                forbid.insert({cu,cv});
            }
        }
    }
    debug() <<imie(forbid);
    ans -= sz(forbid);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}