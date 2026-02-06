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

const int mxn=2e5;
const ll mod = 998244353;
int n,m,mx,t;
int a[mxn];

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
    int me = num[at] = ++Time, e, y, top = me;
    for (auto pa : ed[at]) if (pa.second != par) {
        tie(y, e) = pa;
        if (num[y]) {
            top = min(top, num[y]);
            if (num[y] < me)
                st.push_back(e);
        } else {
            int si = sz(st);
            int up = dfs(y, e, f);
            top = min(top, up);
            if (up == me) {
                st.push_back(e);
                f(vi(st.begin() + si, st.end()));
                st.resize(si);
            }
            else if (up < me) st.push_back(e);
            else { /* e is a bridge */ }
        }
    }
    return top;
}

template<class F>
void bicomps(F f) {
    num.assign(sz(ed), 0);
    rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
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
    cin >>n >>m >>mx;
    rep(i,0,n) {
        cin >>a[i];
    }
    int eid = 0;
    ed.resize(n);
    vector<pii> edl;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        edl.push_back({u,v});
        ed[u].push_back({v,eid});
        ed[v].push_back({u,eid++});
    }
    int nx = mx;
    vector<vi> vnx;
    bool ok = 1;
    UF uf(n);
    bicomps([&](const vi& ved) -> void {
        // debug() <<imie(ved);
        for(const auto& vedi: ved) {
            auto [u,v] = edl[vedi];
            uf.join(u,v);
        }
    });
    vector comp(n,set<int>());
    set<int> cand;
    rep(i,0,n) {
        int pu = uf.find(i);
        if(i==pu && uf.size(pu)==1) {
            continue;
        }
        cand.insert(pu);
        comp[pu].insert(i);
    }
    for(auto& candi: cand) {
        auto& su = comp[candi];
        // debug() <<imie(su);
        map<int,int> cl;
        bool isodd = 0;
        function<void(int)> dfs2;
        dfs2 = [&](int u) -> void {
            if(isodd) return;
            for(const auto& [v,vid]: ed[u]) {
                if(su.count(v)) {
                    if(cl.count(v)) {
                        if(cl[u]==cl[v]) {
                            isodd = 1;
                            return;
                        }
                    } else {
                        cl[v] = 1-cl[u];
                        dfs2(v);
                    }
                }
            }
        };
        cl[*su.begin()] = 1;
        dfs2(*su.begin());
        if(isodd) {
            for(const auto& u : su) {
                if(a[u]>0 && a[u]<mx) {
                    ok = 0;
                    break;
                } else if(a[u]>=mx) {
                    int vnxi = a[u]-mx;
                    for(const auto& u2: vnx[vnxi]) {
                        a[u2] = 0;
                    }
                    vnx[vnxi].clear();
                } else {
                    a[u] = 0;
                }
            }
        } else {
            set<int> vld;
            set<int> luar;
            bool blm = 0;
            for(const auto& u : su) {
                if(a[u]>=0 && a[u]<mx) {
                    vld.insert(a[u]);
                } else if(a[u]==-1) {
                    blm = 1;
                } else {
                    luar.insert(a[u]);
                }
            }
            if(sz(vld)) {
                if(sz(vld)>1) {
                    ok = 0;
                    break;
                }
                int nl = (*vld.begin());
                if(sz(luar)>0 || blm) {
                    for(const auto& u : su) {
                        if(a[u]==-1) {
                            a[u] = (*vld.begin());
                        } else if(a[u]>=mx) {
                            int vnxi = a[u]-mx;
                            for(const auto& u2: vnx[vnxi]) {
                                a[u2] = nl;
                            }
                            vnx[vnxi].clear();                            
                        }
                    }
                }
            } else {
                if(sz(luar)) {
                    int nl = (*luar.begin());
                    int vnl = nl-mx;
                    if(blm || sz(luar)>1) {
                        for(const auto& u : su) {
                            if(a[u]==-1) {
                                a[u] = nl;
                                vnx[vnl].push_back(u);
                            } else if(a[u]!=nl) {
                                int vnxi = a[u]-mx;
                                for(const auto& u2: vnx[vnxi]) {
                                    a[u2] = nl;
                                    vnx[vnl].push_back(u2);
                                }
                                vnx[vnxi].clear();
                            }
                        }
                    }
                } else {
                    vi cur;
                    for(const auto& u : su) {
                        a[u] = nx;
                        cur.push_back(u);
                    }
                    vnx.push_back(cur);
                    nx++;
                }
            }
        }
    }
    if(!ok) {
        cout <<"0\n";
    } else {
        ll ans = 1;
        for(const auto& vnxi: vnx) {
            if(sz(vnxi)) {
                ans = ans*mx%mod;
            }
        }
        rep(i,0,n) {
            if(a[i]==-1) {
                ans = ans*mx%mod;
            }
        }
        cout <<ans <<"\n";
    }
    num.clear(); st.clear(); ed.clear();
    Time = 0;
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