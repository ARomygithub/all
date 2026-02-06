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
int n,t;
const int mxa=2e5;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

void solve() {
    cin >>n;
    vector adj(n, vi());
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int,int)> dfs;
    vi sub(n,0), cl(n,0);
    int k = 0;
    vi v;
    dfs = [&](int u, int p) -> void {
        for(auto v: adj[u]) {
            if(v==p) continue;
            dfs(v,u);
            sub[u] += sub[v];
        }
        sub[u]++;
        cl[u] = (sub[u]%2);
        if(cl[u]==0 || u==0) {
            v.push_back(sub[u]);
        }
        if(cl[u]==0) {
            sub[u] = 0;
        }
    };
    dfs(0,-1);
    ll ans = 1;
    // debug() <<imie(v);
    if(sz(v)>1) {
        rep(i,0,sz(v)-1) {
            ans = ans*v[i]%mod;
            ans = ans*v[i]%mod;
        }
        ans = ans*v.back()%mod;
        ans = ans*fct[(sz(v)-2)]%mod;
        ll sm = 0;
        rep(i,0,sz(v)-1) {
            sm = (sm + iv[v[i]])%mod;
        }
        ans = ans*sm%mod;
    }
    // rep(i,0,k) {
    //     ans = ans*2%mod;
    // }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init_fac();
    while(t--) {
        solve();
    }
}